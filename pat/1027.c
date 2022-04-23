#include<stdio.h>
//(2n+1)*n-1
int main()
{
    int n ;
    char x ;
    scanf("%d %c",&n,&x);
    int i = 1;
    while(n-(2*i)*i+1 >= 0)
        i++;
    int y = i-1;
    int z = n-(2*(i-1))*(i-1)+1;
    for (i = i-1; i > 0; i--)
    {
        for (int j = 0; j < y-i ;j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2*i-1; j++)
        {
            printf("%c",x);
        }
        printf("\n");
    }
    for (i = 2; i <= y; i++)
    {
        for (int j = 0; j < y-i ;j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2*i-1; j++)
        {
            printf("%c",x);
        }
        printf("\n");
    }
    
    printf("%d",z);
}