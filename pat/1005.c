#include <stdio.h>

int main()
{
    int k=0,x=0;
    int sum = 0;
    int list[101] = {0};
    scanf("%d",&k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d",&x);
        list[x] = 1;
    }

    for (int i = 0; i <=100 ; i++)
    {
        int n = i;
        while(n>1 && list[i] )
        {
            
            if((n%2) == 0)
            {   
                n = n/2;
                if(n<=100)
                list[n] = 0;
            }
            else if((n%2) == 1)
            {
                n = (3*n+1)/2;
                if(n<=100)
                list[n] = 0;
            }
                
        }
        
    }
    for (int i = 0; i <= 100; i++)
    {
        sum = sum + list[i];
    }
    //printf("%d\n",sum);
    for (int i = 100; i >= 2; i--)
    {
        if(list[i])
        {
            printf("%d",i);
            if(sum > 1)
            {
                printf(" ");
                sum--;
            }
        }
    }
    
}