#include <stdio.h>
#include <stdlib.h>


typedef struct _node{
    int key;
    struct _node *next;
}node;

node *head;

// void init_list(){
//     head = (node*)calloc(1,sizeof(node));
//     tail = (node*)calloc(1,sizeof(node));
//     head->next = tail;
//     tail->next = tail;
// }



void delete_after(node *t){
    node *temp;
    temp = t->next;
    t->next = t->next->next;
    //temp->next = NULL;
    
    free(temp);//해당 주소에 해당하는 값만 삭제... //temp->next = NULL;나는 free하면 뒤에 줄줄이 따라서 없어질 것으로 생각했음.
}

void print_list(node *t){
    node *temp;
    temp = t->next;
    while (temp != head)//교수님 코드랑 다름 여기는..
    {
        //temp =t;
        printf("%-8d",t->key);  
        t = t->next; 
        temp =t; 
         
         
    }
    
}

void insert_nodes(int k){
    node *t;
    int i;
    t = (node*)calloc(1,sizeof(node));
    t->key=1;
    head = t;
    printf("%c ",(t->key)-1+'A');
    for ( i = 2; i <= k; i++)
    {
        t->next =(node*)calloc(1,sizeof(node));
        t = t->next;
        t->key = i;
        printf("%c ",(t->key)-1+'A');
    }
    t->next = head;
    printf("%c ",(t->next->key)-1+'A');
}

void josephus(int n, int m){
    node *t;
    int i;
    insert_nodes(n);
    t = head;
    printf("\n%c\n",(t->key)-1+'A');
    printf("\nanswer\n");
    while (t != t->next)
    {
        for ( i = 0; i < m-1; i++)
        {
            t = t->next;
            
        }
        printf("%d ",t->key);
        delete_after(t);
        
    }  
    printf("%d ",t->key); 
    
    
}

void main(){
    

    printf("\njosephus\n");
    josephus(5,2);

}