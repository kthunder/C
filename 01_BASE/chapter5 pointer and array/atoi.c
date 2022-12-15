#include<stdio.h>

int atoi(char *s)
{
    int x = 0, sign = 1;
    if (*s == '-')
    {
        sign = -1;
        s++;
    }
    while (*s)
    {
        x = x * 10 + (*s++ - '0');
    }
    return x*sign;
}

int main(int argc, char const *argv[])
{
    char s[100];
    scanf("%s", s);
    printf("%d\n", atoi(s));
    return 0;
}

