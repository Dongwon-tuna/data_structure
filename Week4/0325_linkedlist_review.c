#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node{
    int key;
    struct _node *next;
}node;

node *head,*tail;

void init_list(){
    head = (node*)calloc(1,sizeof(node));
    tail = (node*)calloc(1,sizeof(node));
    head->next = tail;
    tail->next = tail;
}

node *insert_after(int k, node *t){
    node *temp;
    temp = (node*)calloc(1,sizeof(node));//temp 새 주소
    temp->key = k;//temp에 키값 입력
    temp->next = t->next;//temp의 next값은 원래 head의 next
    t->next = temp;//t의 next는 temp의 주소
    return temp;
}


void print(node *a){
    
    printf("insert result head add: %d\n",a);
    printf("next head: %d\n",a->next);
    node *t;
    t = t->next;
    printf("insert result head add1: %d\n",t);
    t = t->next;
    printf("insert result head add2: %d\n",t);
    t = t->next;
    printf("insert result head add3: %d\n",t);

    // while (1)
    // {
    //     t = a->next;
    //     printf("key: %d\n",t->key);
    //     if (t->next == tail)
    //     {
    //         printf("now t is nexting tail\n");
    //         break;
    //     }

    // }
    
  
    
}
void main(){
    init_list();
    printf("init head address: %d\n",head);
    printf("init tail address: %d\n",tail);
    //insert_after(4,insert_after(3,head));
    printf("after insert func in main order %d\n",insert_after(5,head));
    insert_after(6,insert_after(5,head));
    //insert_after(5,head->next);
    //printf("init head next address: %d\n",head->next);
    //printf("after insert func in main order %d\n",insert_after(4,head->next));
    print(head);


        

}