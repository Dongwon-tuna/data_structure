#include <stdio.h>
#include <stdlib.h>
//구조체와 포인터 배열의 복습
typedef struct node1{
    int a;
    int b;
}node;//typedef를 활용한 구조체 생성

node *arr[10];//주소를 저장할 수 있는 포인터>>arr[i]의 값은 주소만 저장 가능
void main(){
    printf("hello\n");
    node *t;//새로운 구조체 포인터 *t를 생성하고,
    t = (node*)malloc(sizeof(node));//memory allocate를 해주고 주소를 t자체에 저장
    arr[0] = t;//0번째 배열의 주소는 t의 주소
    arr[0]->a = 10;//포인터를 활용하여 요소에 접근하여 값 수정 
    arr[0]->b = 20;
    printf("first one: %d  second one:%d\n",arr[0]->a,arr[0]->b);
   

}