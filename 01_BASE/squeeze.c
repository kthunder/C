#include <stdio.h>
#include <string.h>
int main()
{
    char s1[20];
    char s2[20];
    scanf("%s %s",s1,s2);
    int length1 = strlen(s1);
    int length2 = strlen(s2);
    for(int i=0 ; i<length1; i++)
    {
        for(int j=0; j<length2; j++)
        {
            if(s1[i] == s2[j])
            {
                s1[i] = '\0';
            }
        }
    }
    for(int i=0; i<length1 ;i++)
    {
        if(s1[i]!='\0')
        putchar(s1[i]);
    }
}