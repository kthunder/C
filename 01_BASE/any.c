#include <stdio.h>
#include <string.h>
int main()
{
    char s1[20];
    char s2[20];
    int n = 0;
    int flag = 0;
    scanf("%s %s",s1,s2);
    int length1 = strlen(s1);
    int length2 = strlen(s2);
    for(int i=0 ; i<length1-length2; i++)
    {
        for(int j=0; j<length2; j++)
        {
            if(s1[i+j] == s2[j])
            {
                n += 1;
                //putchar(s2[j]);
            }
            if(j == length2-1 && n == length2)
            {
                printf("%d",i);
                n = 0;
                flag = 1;    
            }
                           
        }
        if(flag == 1)
            break;
    }
    if(flag != 1)
        printf("-1");
    
}