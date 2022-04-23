#include<stdio.h>
#include<ctype.h>

int main()
{
    char keytab[128] = {1,};
    for (int i = 0; i < 128; i++)
    {
        keytab[i] = 1;
    }

    char c;
    while((c = getchar()) != '\n')
    {
        if (islower(c))
            keytab[c - ('a' - 'A')] = 0;
        else if(isupper(c))
            keytab[c + ('a' - 'A')] = 0;
        keytab[c] = 0;
    }
    while((c = getchar()) != '\n')
    {
        if (isalpha(c))
        {
            if (islower(c) && keytab[c] == 1)
            {
                putchar(c);
            }
            else if(isupper(c) && keytab[c] == 1 && keytab['+'] == 1)
            {
                putchar(c);
            }
        }
        else if(keytab[c] == 1)
        {
            putchar(c);
        }
    }
    return 0;
}
