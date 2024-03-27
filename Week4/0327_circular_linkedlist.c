#include <stdio.h>
#include <stdlib.h>


typedef struct _node{
    int key;
    struct _node *next;
}node;

node *head;


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

void josephus(int n, int m){//총 n명의 인원중에서 m 번째 인원을 제거시키고, 다음 과정을 계속 수행.
    node *t;
    
    insert_nodes(n);
    t = head;
    printf("\nAnswer\n");
    
    while (t != t->next)
    {
       
        for (int i = 0; i < m-2 ; i++)
        {
            t = t->next;
        }
        
        printf("%d ",t->next->key);
        delete_after(t);
        t = t->next;
        
    }
    t = t->next;
    printf("%d ",t->next->key);
    
    
}

void main(){
    

    printf("\njosephus\n");
    josephus(5,3);

}