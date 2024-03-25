#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int key;
    struct _node *next;
}node;


node *head, *tail;

void init_list(){
    head = (node *)calloc(1,sizeof(node));
    tail = (node *)calloc(1,sizeof(node));
    head->next =tail;
    tail->next = tail;
}

int cnt = 1;

node *find_node(int k){
    node *temp;

    temp = head ->next;
    while (temp->key !=k&&temp!=tail)
    {
        temp = temp->next;
        cnt ++;
    }

    return temp;
    
}

node *ordered_insert(int k){
    node *s, *p, *r;
    
    p =head;
    s = p->next;
    while (s->key <=k &&s!=tail)
    {
        p = p ->next;
        s= p->next;
    }
    r = (node *) calloc(1,sizeof(node));
    r->key = k;
    p->next = r;
    r->next = s;
    return r;
    
}

void print_list(node *t){
    while (t->next != tail)//교수님 코드랑 다름 여기는..
    {
        t = t->next;
        printf("%-8d",t->key);
        
        
    }
    
}
void main(){
    init_list();
    node *res;
    res = ordered_insert(9);
    res = ordered_insert(7);
    res = ordered_insert(5);
    res = ordered_insert(3);
    res = ordered_insert(1);
    print_list(head);
    res = find_node(5);
    printf("order: %d\n",cnt);
}