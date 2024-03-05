#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Throw a dice 100 times and compute the frequency

int *diceInfo(int numDice){
    static int dicdSide[6]={0,};
    for (int i = 0; i < numDice; i++)
    {
        int randNum = rand()%6+1;
        dicdSide[randNum-1] = dicdSide[randNum-1]+1;

    }
    return dicdSide;
    
}

int main(void){
    srand(time(NULL));
    int numDice;
    printf("Input:");
    scanf("%d",&numDice);
    int *output = diceInfo(numDice);

    for (int i = 0; i < 6; i++)
    {
        printf("%d : %d\n",i+1,output[i]);
    }
    

}