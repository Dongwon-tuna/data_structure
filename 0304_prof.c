#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void TossDice(int num){
    
    int k,diceNum;
    int numCnt[6]={0};
    //int * numCnt = (int*)calloc(6,sizeof(int));

    for (int k = 0; k < num; k++)
    {
        diceNum = rand() %6 + 1;
        numCnt[diceNum -1] ++;
        //printf("%d\n",k);
    }

    for (size_t i = 0; i <6; i++)
    {
        printf("dice counts %d = %d (%.3f)\n",i+1,numCnt[i],numCnt[i]/(float)num);
    }
    
}   

void main(){
    int num;
    srand((unsigned)time(NULL));
    //strand(time)
    printf("input");
    scanf("%d",&num);
    TossDice(num);
    
}


