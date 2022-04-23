#include<stdio.h>
int main()
{
    int n ;
    scanf("%d",&n);
    int x;
    int i;
    int a[3] = {0};
    for (i = 0; n >= 10 ; i++)
    {
        a[i] = n%10;
        n = n/10;
    }
    a[i]=n;
    for (  ; i >= 0; i--)
    {
        if(i == 2)
            for (int j = 0; j < a[i]; j++)
            {
                printf("B");
            }
        else if(i == 1)
        {
             for (int j = 0; j < a[i]; j++)
            {
                printf("S");
            }
        }
        else
        {
            for (int j = 1; j <= a[i]; j++)
            {
                printf("%d",j);
            }
            
        }
         
            
    }
    
}