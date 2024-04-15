#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
#define ROWLENGTH 15
#define COLLENGTH 15


// int input_map[9][9]={
//     {0,1,0,0,0,1},
//     {0,0,1,1,0,1},
//     {0,1,0,1,0,1},
//     {1,0,0,0,0,1},
//     {0,1,0,1,0,1},
//     {0,0,0,0,1,1},
//     {0,0,0,0,0,1},
//     {0,0,0,1,1,1},
//     {0,0,0,0,1,1}
// };


int cnt = 1;
int input_map[ROWLENGTH][COLLENGTH] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0},
	{0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0},
	{0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0},
	{0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
	{0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0},
	{0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0},
	{0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0},
	{0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0},
	{0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0},
	{0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
typedef struct _hwd{
    int row;
    int col;
    int direction;
    struct _hwd *next;

}hwd;


hwd stack[MAX];
hwd *head;
hwd *tail;
void init_stack(){
    head = (hwd*)calloc(1,sizeof(hwd));
    tail = (hwd*)calloc(1,sizeof(hwd));
    head->next = tail;
    tail->next = tail;
}

hwd push(int row, int col,int dir){
    hwd *t;
    t = (hwd*)calloc(1,sizeof(hwd));
    t->row = row;
    t->col = col;
    t->direction = dir;
    t->next = head->next;
    head ->next = t;
    return *t;
}

hwd pop(){
    hwd *t;
    hwd k;
    if(head->next == tail){
        printf("underflow\n");
    }
    t = head->next;
    k = *t;
    head->next = t->next;
    free(t);
    return k;
}

int search(int row, int col){
   

    if(input_map[row-1][col]==1){
        return 0;
    }
    else if(input_map[row-1][col+1]==1){
        return 1;
    }
    else if(input_map[row][col+1]==1){
        return 2;
    }
    else if(input_map[row+1][col+1]==1){
        return 3;
    }
    else if(input_map[row+1][col]==1){
        return 4;
    }
    else if(input_map[row+1][col-1]==1){
        return 5;
    }
    else if(input_map[row][col-1]==1){
        return 6;
    }
    else if(input_map[row-1][col-1]==1){
        return 7;
    }
    else return -1;
}

void change(int row,int col){
    input_map[row][col] = cnt;
}


int detection(int row, int col){
    int searchres = search(row,col);
    hwd popRes;
    if (searchres!=-1)
    {
        
        push(row,col,searchres);
        if(searchres == 0)
        {
            change(--row,col);
            detection(row,col);
            
        }
        else if (searchres == 1)
        {
            change(--row,++col);
            detection(row,col);
        }
        else if (searchres == 2)
        {
            change(row,++col);
            detection(row,col);

        }
        else if (searchres == 3)
        {
            change(++row,++col);
            detection(row,col);
        }
        else if (searchres == 4)
        {
            change(++row,col);
            detection(row,col);

        }
        else if (searchres == 5)
        {
            change(++row,--col);
            detection(row,col);

        }
        else if (searchres == 6)
        {
            change(row,--col);
            detection(row,col);

        }
        else if (searchres == 7)
        {
            change(--row,--col);
            detection(row,col);

        }
        
    }
    else{
        
        if (head->next == tail)
        {
            return 0;
        }
        popRes = pop();
        
        detection(popRes.row,popRes.col);
        
        

    }
    
    //
    
}

void main(){
    
    
    init_stack();
    
    

    for (int i = 0; i <ROWLENGTH ; i++)
    {
        for (int j = 0; j < COLLENGTH; j++)
        {
            if (search(i,j) !=-1)
            {
                cnt++;
            }
            
            detection(i,j);
        }
    
    }
    

    for (int i = 0; i <ROWLENGTH ; i++)
    {
        for (int j = 0; j < COLLENGTH; j++)
        {
            printf("%d ",input_map[i][j]);
        }
        printf("\n");
        
    }
    
    
       
}