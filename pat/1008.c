#include<stdio.h>
int main()
{
    
    int n,m,x;
    scanf("%d %d",&n,&m);
    int arrays[101];
    for (int i = 0; i < n; i++)
    {
        x = (i+m>n-1? (i+m-n) : i+m);
        while(x>=n)
            x-=n;
        scanf("%d",&arrays[x]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d",arrays[i]);
        if (i != n-1)
        printf(" ");
    }
}