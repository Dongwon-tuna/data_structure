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

int push(int k){
    node *t;
    if((t=(node*)malloc(sizeof(node))) == NULL){
        printf("out of memeory\n");
        return -1;
    }
    t=(node*)malloc(sizeof(node));
    t->key = k;
    t->next = head->next;
    head->next = t;
    //printf("%d\n",t);
    return k;
}

int pop(){
    node *t;
    int k;
    if(head->next == tail){
        printf("stack underflow\n");
        return -1;

    }
    t = head->next;
    k = t->key;
    head->next = t->next;
    free(t);

    return k;
}

void clear(){
    node *t,*s;
    t= head->next;

    while (t != tail)
    {
        s = t;
        t = t->next;
        free(s);
    }
    head->next = tail;
    
}

void main(){
    init_list();
    int input;
    while (1)
    {
        printf("input num");
        scanf("%d",&input);
        push(input);
        if (input == 100)
        {
            pop();
            break;;
        }
        
    }
    //clear();

    while (head->next != tail)
    {
        printf("pop: %d\n",pop());
    }
    
    
    
}