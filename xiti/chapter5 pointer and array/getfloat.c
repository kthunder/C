#include <ctype.h>
#include <stdio.h>
#define SIZE 8 //数组长度
#define BUFSIZE 100

char buf[BUFSIZE] = {0};
int bufp = 0;
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
       printf("ungetch: too many characters\n");
    else
       buf[bufp++] = c;
}

//getint : get next integer from input into *pn
int getfloat(float *pn)
{
    int c, sign;
    float x;
    while (isspace( c = getch() )) // skip whith space
    {


    }
    if (c == EOF)
    {
        *pn = 0;
        return c;
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
    if(!isdigit(c))
    {
        *pn = 0;
        if (c!=EOF)
        {
            ungetch(c);
        }
        return c;
    }
    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10.0 * (*pn) + (c - '0');
    }
    if (c == '.')
    {

        c = getch();
        for ( x = 1.0; isdigit(c);c = getch())
        {
            *pn =  10.0 * (*pn) + (c - '0');
            x *= 10.0;
        }

    }

    *pn *= (sign / x);
    if (c!=EOF)
    {
        ungetch(c);
    }
    return c;
}

int main()
{
    float array[SIZE] = {0};

    for (int n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
        ;
    for (int n = 0; n < SIZE; n++)
        printf("%f ", array[n]);
    printf("\n");
    return 0;
}
