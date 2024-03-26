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
    
    node *t;
    t = a;
    printf("======================\nhead address: %d\n",t);
    t = t->next;
    while (t != tail)
    {
        printf("======================\n");
        printf("added address: %d\n",t);
        printf("added key: %d\n",t->key);
        
        t = t->next;
    }
    printf("======================\ntail address: %d\n",t);
    
  
    
}
void main(){
    init_list();
    printf("init head address: %d\n",head);
    printf("init tail address: %d\n",tail);
    //insert_after(4,insert_after(3,head));
    node *a;
    a = insert_after(5,head);
    node *b;
    b = insert_after(6,a);
    node *c;
    c =insert_after(7,b);
    insert_after(8,c);
    
    print(head);


        

}