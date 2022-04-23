#include <ctype.h>

#define EOF -1

int getch(void);
void ungetch(int);

//getint : get next integer from input into *pn
int getint(int *pn)
{
    int c, sign;

    while (isspace( c = getch() )) // skip whith space
    {
        /* code */
    }

    if (!isdigit(c) && c != EOF && c != '+' && c!= '-')
    {
        ungetch(c); // it's not a number
        return 0;
        /* code */
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '-' || c == '+')
    {
        c = getch(); /* code */
    }
    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c!=EOF)
    {
        ungetch(c);
    }
    return c;
}
