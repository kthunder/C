#include<stdio.h>
#include <math.h>
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
int howlong(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (isPrime(i)==1)
        {
            count++;
        }
        
    }
    return count;
}

int main()
{
    int n;
    scanf("%d",&n);
    int j = 0;
    int lenth;
    lenth = howlong(n);
    int arrays[lenth];
    int x= 0;
    for (int i = 1; i <= n; i++)
    {
        if(isPrime(i) == 1)
        {
            arrays[j] = i;
            j++;
        }
            
    }
    for (int i = 0; i < lenth-1; i++)
    {
        if (arrays[i+1]-arrays[i]==2)
        {
            x++;
        }
        
    }
    printf("%d\n",x);
}
