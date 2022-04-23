#include<stdio.h>
#include<string.h>
int main()
{
    char number[1001];
    char quotient[1000];
    //char remainder;
    int divisor;
    int length;
    int q,n,r = 0;
    int j = 0;
    scanf("%s %d",number,&divisor);
    length = strlen(number);
    for (int i = 0; i < length; i++)
    {
        n = number[i]-48 + 10*r;
        q = n/divisor;
        r = n%divisor;
        if (1)
        {
            quotient[j] = q + 48;
            j++;
        }
        
    }
    if(quotient[0]!='0')
        putchar(quotient[0]);
    else if (strlen(quotient) == 1)
    {
        putchar(quotient[0]);
    }
    
    for (int i = 1; quotient[i] !='\0'; i++)
    {
        
        putchar(quotient[i]);
    }
    printf(" %d",r);
    
}