#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE 100
#define MAX 90

typedef struct _dnode{
    int key;
    struct _dnode *prev;
    struct _dnode *next;
}dnode;

dnode *head, *tail;

int check[MAX_NODE];
int check2[MAX_NODE];


int GM[MAX_NODE][MAX_NODE];
dnode *GL[MAX_NODE];

int name2int(char c) {
    return c - 'A';
}

char int2name(int i) {
    return i + 'A';
}

int visit(int k){
    printf("%d\n",k);
}

void init_queue(){
    head = (dnode*)calloc(1,sizeof(dnode));
    tail = (dnode*)calloc(1,sizeof(dnode));
    head->prev = head;
    head->next = tail;
    tail->prev = head;
    tail->next = tail;
}

int put(int k){//k는 데이터
    dnode *t;
    t=(dnode*)malloc(sizeof(dnode));
    t->key = k;
    tail->prev->next = t;
    t->prev = tail->prev;
    tail->prev = t;
    t->next = tail;
    return k;
}

int get(){
    dnode *t;
    int k;
    t = head->next;
    if (t == tail)
    {
        printf("underflow\n");
        return-1;
    }
    k = t->key;
    head->next = t->next;
    t->next->prev = head;
    free(t);
    return k;
    
}


void print_queue(){
    dnode *t;
    t = head->next;
    while (t!=tail)
    {
        printf("%-6d",t->key);
        t = t->next;
    }
    
}

void main(){
    
    init_queue();
    int in=0;

    while (1)
    {
        printf("put the value\n");
        scanf("%d",&in);
        put(in);
        if (in == 100)
        {
            get();
            break;
        }
        
    }
    
    
    
    print_queue();

    
}