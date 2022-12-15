#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    printf("location of add 0 : %d\n", *(int *)0);
    printf("location of code : %p\n", (void *)main);
    printf("location of heap : %p\n", (void *)malloc(1));
    int x = 3;
    printf("location of stack : %p\n", (void *)&x);
    return x;
}