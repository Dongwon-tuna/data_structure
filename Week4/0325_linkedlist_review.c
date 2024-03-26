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

node *delete_next(node *t){
    node *temp;
    temp = t->next;
    t->next = t->next->next;
    //temp->next = NULL;
    
    free(temp);//해당 주소에 해당하는 값만 삭제... //temp->next = NULL;나는 free하면 뒤에 줄줄이 따라서 없어질 것으로 생각했음.
}

int numcnt=0;

node *find_key(int k,node *t){
    static int order[1] = {0};
    
    node *before;
    while (t->key!=k)
    {
        numcnt++;
        before = t;
        
        t = t->next;
       // printf("%d\n",t->key);
    }
    return before;
    
}

void delete_givenKey(int k){
    node *before;
    node *t;
    t = head;
    while (t->key!=k)
    {
        before = t;
        t = t->next;//해당 key 찾고 free 당하는 역할, 즉 척후병
    }
    before->next = t->next;
    free(t);
}

void insert_between(int x, int y){
    node *before,*after,*new;
    before = head;
    after = before->next;
    while (before->key!=x&&after->key!=y)
    {
        before = before->next;
        after = before->next;
    }
    new =  (node*)calloc(1,sizeof(node));
    before->next = new;
    new->next = after;
    new->key = 12;

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
    print(head);// 삽입한 값을 출력
    delete_next(head);//head 다음 값을 지움
    printf("\n##########delte func##########\n\n");
    print(head);

    node *find;
    find = find_key(8,head);//8이 담겨있는 노드의 정보 확인
    printf("\n%d is at %d at %d order\n",find->next->key, find->next,numcnt);

    delete_givenKey(8);//8이 key값으로 있는 노드를 지움
    printf("\n##########delte given key##########\n\n");
    print(head);
    printf("\n##########insert new node between given key##########\n\n");
    insert_between(6,7);
    print(head);
        

}