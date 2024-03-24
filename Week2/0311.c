//22차원 배열 포인터 관점으로
#include <stdio.h>
#include <stdlib.h>
int *add(int x, int y);
void main(){
    int *res;
    res = add(5,9);
    printf("res: %d",*res);
}

int *add(int x, int y){
    int *z;
    z = (int*)malloc(sizeof(int));
    *z = x+y;
    return z;
    
}