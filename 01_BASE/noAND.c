#include<stdio.h>

#define MAX_LIMIT 10

int main()
{
    int c;
    int i;

    for ( i = 0; i < MAX_LIMIT; i++)
    {
        if((c = getchar()) == 'r' )
            break;
        else if (c == EOF)
            break;
        else
            putchar(c);    
        
    }
    
}