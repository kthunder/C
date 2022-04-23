#include<stdio.h>

int main()
{
    int table[127] = {0};
    int len = 0;
    char str[2000000];
    char ch;

    while ((ch = getchar()) != '\n')
    {
        str[len++] = ch;
    }
    while ((ch = getchar()) != '\n')
    {
        str[len++] = ch;
    }
    str[len] = '\0';

    for (int i = 0; str[i]!='\0'; i++)
    {
        table[str[i]] = 1;
    }

    for (int i = 0; str[i]!='\0'; i++)
    {
        if (table[str[i]] == 1)
        {
            putchar(str[i]);
            table[str[i]] = 0;
        }

    }


    return 0;
}
