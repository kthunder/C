#include<stdio.h>
#define MAXLEN 50

int strcmp(char *s ,char *t)
{
    for (;*s == *t  ; s++,t++)
        if (*s)
            return 0;
    return *s - *t;
}

int strrindex(char *s,char *t)
{
    int flag = -1;
    for (int i = 0; *t&&*s ; i++)
    {
        if (!strcmp(s,t))
        {
            flag = i;
            *s++;
        }
        else
            *s++;
        if (!*(s+1))
            return flag;
    }
}

int main(int argc, char const *argv[])
{
    char s[MAXLEN];
    char t[MAXLEN];
    scanf("%s %s", s, t);
    printf("%d\n", strrindex(s, t));
    return 0;
}
