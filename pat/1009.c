#include<stdio.h>
#include<string.h>
int main()
{
    int szmwz;
    int str[23];
    int destr[23];
    int lenth = 0 , count = 0 , c;
    for(int i = 0;(c = getchar()) != 10; i++)
    {
        str[i] = c;
        lenth ++;
    }
    for (int i = 0; i < lenth; i++)
        destr[i] = str[i];
    
    for (int i = 0; i < lenth; i++)
    {
        if((str[i] != 32 )&&(str[i] != EOF))
            count++;

        else
        {
            szmwz = i - count;
            for (int j = 0; j < count; j++)
            {
                destr[lenth - i  + j] = str[szmwz+j];
            }
            destr[lenth - i-1] = str[i];
            count = 0;
        }
        while(i == lenth-1)
        {
            i++;
            szmwz = i - count;
            for (int j = 0; j < count; j++)
            {
                destr[lenth - i  + j] = str[szmwz+j];
            }
            //destr[lenth - i-1] = str[i];
            count = 0;
        }

        
    }
    for (int i = 0; i < lenth; i++)
    {
        printf("%c",destr[i]);
    }
    
}