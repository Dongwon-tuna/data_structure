#include <stdio.h>

void main(){
    char buffer[8];
    int *pi;

    pi = (int *)buffer;
    *pi = 12;
    *(pi + 1) = 34;
    printf("%d %d",*pi,*(pi +1));
}