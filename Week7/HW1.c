#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWLENGTH 15
#define COLLENGTH 15
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
typedef struct _hwd{//Linked lsit Stack을 사용하기 위한 구조체(hwd값을 모두 포함하여 stack에 넣는다)
    int row;//행 성분이 저장되는 변수
    int col;//열 성분이 저장되는 변수
    int direction;//0~7까지 방향이 저장되는 변수
    struct _hwd *next;

}hwd;

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

int search(int row, int col){//현재 위치를 기준으로 상 하 좌 우 대각선 성분중 어디가 색칠된 위치인치 파악하는 함수
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
    else return -1;//주변 성분이 유의미 하지 않은 경우
}

void change(int row,int col){//색칠된 영역을 색칠하는 함수
    input_map[row][col] = cnt;
}


int detection(int row, int col){//Recursion을 사용하여 연결된 부분을 같은 색깔로 칠하는 과정을 진행하는 함수
    int searchres = search(row,col);
    hwd popRes;//pop()의 결과를 저장하는 변수
    if (searchres!=-1)//현재 위치를 기준으로 주변에 색칠 해야할 영역을 판단한다.
    {
        push(row,col,searchres);//주변에 유의미한 값이 있을 떄 hwd를 stack에 넣는다
        if(searchres == 0)//d가 0방향인 경우
        {
            change(--row,col);//유의미한 값이 검출되면  hwd에 의해서 그 위치를 방문한다. 그리고 그 영역을 특정 색깔로 칠한다
            detection(row,col);//recursion을 사용하여 현재의 위치와 연관된 유의미한 값들의 꼬리를 물어서 접근한다
            
        }
        else if (searchres == 1)//d가 1방향인 경우
        {
            change(--row,++col);
            detection(row,col);
        }
        else if (searchres == 2)//d가 2방향인 경우
        {
            change(row,++col);
            detection(row,col);

        }
        else if (searchres == 3)//d가 3방향인 경우
        {
            change(++row,++col);
            detection(row,col);
        }
        else if (searchres == 4)//d가 4방향인 경우
        {
            change(++row,col);
            detection(row,col);

        }
        else if (searchres == 5)//d가 5방향인 경우
        {
            change(++row,--col);
            detection(row,col);

        }
        else if (searchres == 6)//d가 6방향인 경우
        {
            change(row,--col);
            detection(row,col);

        }
        else if (searchres == 7)//d가 7방향인 경우
        {
            change(--row,--col);
            detection(row,col);

        }
        
    }
    else{//주변에 방문할 수 있는 유의미한 값이 없는 경우
        if (head->next == tail)//recursion의 terminate condition(스택이 비어있으면 연결된 모든 영역을 다 방문한 것이다.)
        {
            return 0;
        }
        popRes = pop();//push한 스택을 pop한다
        detection(popRes.row,popRes.col);//pop한 스택에 담긴 위치에서 다시 주변의 유의미 한 값을 탐색하게 recursion을 진행한다
    }
}

void main(){
    init_stack();//스택을 초기화
    
    for (int i = 0; i <ROWLENGTH ; i++)//주어진 15 by 15 matrix의 지점을 모두 방문하면서 주변을 탐색한다.
    {
        for (int j = 0; j < COLLENGTH; j++)
        {
            if (search(i,j) !=-1)
            {
                cnt++;//방문한 영역의 순서를 하나씩 올려서 독립된 영역이 모두다른 색으로 칠해지게 해 주는 성분
            }
            
            detection(i,j);//해당 좌표 근처의 유의미한 값을 탐색한다
        }
    
    }
    

    for (int i = 0; i <ROWLENGTH ; i++)//결과를 출력한다
    {
        for (int j = 0; j < COLLENGTH; j++)
        {
            printf("%d ",input_map[i][j]);
        }
        printf("\n");
        
    }
    
    
       
}