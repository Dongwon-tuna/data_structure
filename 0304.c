#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
    srand(time(NULL));
    int num;
    printf("number:");
    scanf("%d",&num);
    int parr[6] = {0,};
    for (int i = 0; i < num; i++)
    {
        int random = rand() % 6+1;
        parr[random-1]= parr[random-1] + 1;
        printf("%d\n",random);

    }
    for (int i = 0; i < 6; i++)
    {
        printf("%d: %d\n",i+1, parr[i]);
    }
    
    //find most frequent number...> algorithm need!!
}