#include <stdio.h>
#include<string.h>

#define MAXLEN 10000
int main()
{
    char number[MAXLEN];
    char c;
    int exp ;
    int expsign ;
    int sign = (getchar() == '-' ? -1 : 1);
    for (int i = 0; (c = getchar())!='E';)
    {
        if (c == '.')
                continue;
        number[i] = c;
        i++;
    }
    expsign = (getchar() == '-' ? -1 : 1);
    scanf("%d", &exp);

    if (sign == -1)
    {
        putchar('-');
    }

    if(expsign < 0)
    {
        for (int i = 0; i < exp; i++)
        {
            putchar('0');
            if (i == 0)
            {
                putchar('.');
            }
        }
        printf("%s", number);
    }
    else if(expsign > 0)
    {
        if (exp >= (strlen(number) - 1))
        {
            for (int i = (strlen(number)); i <= (exp + 1); i++)
            {
                number[i] = '0';
                if (i == (exp +1))
                {
                    number[i ] = '\0';
                }
            }
            printf("%s", number);
            return 0 ;
        }


        for (int i = 0; number[i] != '\0'; i++)
        {
            putchar(number[i]);
            if (i == exp)
            {
                putchar('.');
            }

        }

    }

}
