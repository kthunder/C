#include <stdio.h>

int main()
{
    int n ;
    char c;
    scanf("%d %c",&n,&c);
    for (int i = 0; i < (n+1)/2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i == 0||j == 0||j == n-1||i == (n+1)/2-1)
                printf("%c",c);
            else
                printf(" ");
            
            if(j == n-1)
                printf("\n");
        }
        
    }
    
}