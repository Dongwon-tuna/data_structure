#include <stdio.h>
#include <stdlib.h>

#define SIZE 5


//------------flip array, mul array.
int *reversArr(int arr[]){
    static int revarr[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        revarr[SIZE-1-i] = arr[i];
    }
    return revarr;
    
}

int *multiplyArr(int arr1[], int arr2[]){
    static int mularr[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        mularr[i] = arr1[i]*arr2[i];
    }
    return mularr;
    
}


int main(void){
    int a[SIZE] = {1,2,3,4,5};
    int *b = reversArr(a);
    int *c = multiplyArr(a,b);
   
    for (int i = 0; i < SIZE; i++)
    {
        printf("a: %d, b: %d, c: %d\n", a[i], b[i],c[i]);
    }
 
    
}