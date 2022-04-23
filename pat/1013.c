#include<stdio.h>

int isPrime(int n) 
{
    if(n==1)
        return 0;
    for (int i = 2; i*i <= n; i++)
    {
        if (n%i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int m,n;
    int j = 1;
    scanf("%d %d",&m,&n);
    int arrayss[n+1];
    for (int i = 2; j <= n; i++)
    {
        if (isPrime(i)==1)
        {
            arrayss[j] = i;
            j++;
        }
        
    }
    for (int i = m; i <= n; i++)
    {
        printf("%d",arrayss[i]);
        
        if(i==n)
            printf("");
        else if((i-m+1)%10!=0)
            printf(" ");
        else
            printf("\n");
        
    }
    
    
}