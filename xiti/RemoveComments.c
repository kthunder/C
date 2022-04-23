#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LENGTH 30

int main()
{
    int inComments = -1,inDoubleQuotationMarks = -1;
    int length;
    char str[LENGTH];
    //scanf("%s",string);
    gets(str);
    length = strlen(str);
    for (int i = 0; i < length; i++)
    {
        if (str[i-1] == '\\')
        {
            putchar(str[i]);
            continue;
        }
        
        if (str[i] == '"'&&inComments != 1)
            inDoubleQuotationMarks *= -1;
        if(str[i] == '/'&&str[i+1] == '*'&&inDoubleQuotationMarks != 1)
            inComments = 1;
        if(str[i-2] == '*'&&str[i-1] == '/'&&inDoubleQuotationMarks != 1)
            inComments = -1;

        if (inDoubleQuotationMarks == 1)
        {
            putchar(str[i]);
        }
        else if(inDoubleQuotationMarks != 1 && inComments != 1)
        {
            putchar(str[i]);
        }   
    }
    
    //printf("\n%s",string);
}