#include <stdio.h>

int main()
{
    int n = 0;
    int i = 0;
    scanf("%d",&n);
    for (i = 0; n != 1; i++)
    {
        if((n%2) == 0)
            n = n/2;
        else if((n%2) == 1)
            n = (3*n+1)/2;
    }
    printf("%d",i);
}