#include<stdio.h>
#define MAXLEN 50

int strcmp(char *s ,char *t)
{
    for (;*s == *t  ; s++,t++)
        if (*s)
            return 0;
    return *s - *t;
}

int strindex(char *s,char *t)
{
    for (int i = 0; *t&&*s ; i++)
    {
        if (!strcmp(s,t))
            return i;
        else
            *s++;
        if (!*(s+1))
            return -1;
    }
}

int main(int argc, char const *argv[])
{
    char s[MAXLEN];
    char t[MAXLEN];
    scanf("%s %s", s, t);
    printf("%d\n", strindex(s, t));
    return 0;
}
