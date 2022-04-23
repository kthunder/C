#include<stdio.h>
int main()
{
    int t;
    long a,b,c;
    scanf("%d",&t);
    for (int i = 0; i < t; i++)
    {
        scanf("%ld %ld %ld",&a,&b,&c);
        printf("Case #%d: ",i);
        if (a+b>c)
        printf("true\n");
        else
        printf("false\n");
    }
}