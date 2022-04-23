#include<stdio.h>
#include<ctype.h>

int main()
{
    char str1[81], str2[81],tab[128] = {0};
    scanf("%s %s", str1, str2);
    char *p1 = str1;
    char *p2 = str2;
    char c;
    for (; *p1 ;)
    {
        if(*p1 != *p2)
        {
            if (tab[toupper(*p1)])
            {
                p1++;
            }
            else
            {
                putchar(toupper(*p1));
                tab[toupper(*p1)] = 1;
                p1++;
            }

        }
        else
        {
            p1++;
            p2++;
        }
    }

    return 0;
}
