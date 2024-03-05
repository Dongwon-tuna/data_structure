#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define size 10
#define SIZE 5


int main(void){

    //array=====================================================================================
    
    int numb = 10;
    int score2[numb];
    int l2 = sizeof(score2);
    score2[9] = 2;
    printf("%d is size, %d is value of 10th info\n",l2,score2[9]);

    // printf("Input:");
    // int in;
    // scanf("%d",&in);
    // int score3[in];
    // int l3 = sizeof(score3);
    // score3[in-1] = 3;
    // printf("%d is size, %d is value of 10 info\n",l3,score3[in-1]);

    /*
    int j;
    int score4[SIZE];
    for (j = 0; j < SIZE; j++)
    {
        score4[j] = 92;
    }

    for (j = 0; j < SIZE; j++)
    {
        printf("%d\n",score4[j]);
    }
    */


    //pointer==========================================================================================
    
    /*
    int j =9;
    int *p = NULL;

     p = &j;

     printf("j = %d\n",j);
     printf("p = %d\n",p);
     printf("*p = %d\n",*p);
    */


   /*
    int j = 9;
    int *p;

    p = &j;
    printf("j = %d\n",j);

    *p =39;
    printf("j = %d\n",j);
    
   */


    /*
   
    printf("hi\n");
    char *pc;
    int *pi;
    float *pf;

    pc = (char *)1000;
    pi = (int *)1000;
    pf = (float *)1000;
    printf("%c, %d, %f",pc+2,pi+2,pf+2);
    */


   /*
   
    int j=9;
    int *p = &j;

    printf("j = %d p =%d \n",j,p);
    (*p)++;
    printf("j = %d p =%d \n",j,p);

    printf("j = %d p =%d \n",j,p);
    *p++;
    printf("j = %d p =%d \n",j,p);
    */

   /*
    int a = 9;
    int b = 39;
    int *pt;

    pt = &a;
    b = *pt;

    printf("b :%d",b);
    */

   /**/
   int a = 9;
   int *pt1,*pt2;

   pt1 = &a;
   pt2 = &a+1;
   *pt2 = 39;
   printf("*(pt1+1): %d, %d\n",*(pt1+1),pt1);//adress added by size of int
   printf("*(pt1)+1: %d\n",*(pt1)+1);
}