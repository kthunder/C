#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int isNumber(char *s)
{
    int dot = 0;
    int i = 0;
    if (*s == '-')//skip '-'
        s++;
    while (*s)
    {
        if(!((isdigit(*s))||*s == '.'))
            return 0;//如果不是数字或者点就返回0
        if (*s == '.')
        {
            dot++;
            if (dot>1)
                return 0;
        }
        if (dot == 1 && isdigit(*s))
        {
            i++;
            if (i>2)
                return 0;
        }
        s++;
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    int num = 0;
    int legals = 0;
    double temp;
    char str[100];
    double sum = 0;
    scanf("%d", &num);
    for (size_t i = 0; i < num; i++)
    {
        scanf("%s", str);
        if (isNumber(str))
        {
            temp = atof(str);
            if (temp >= -1000&&temp <= 1000)
            {
                sum += temp;
                legals++;
            }
            else
                printf("ERROR: %s is not a legal number\n",str);
        }
        else
            printf("ERROR: %s is not a legal number\n",str);
    }
    if (legals!=0)
    {
        if (legals == 1)
            printf("The average of %d number is %.2lf", legals ,sum / legals);
        else
            printf("The average of %d numbers is %.2lf", legals ,sum / legals);
    }
    else
        printf("The average of %d numbers is Undefined", legals);
    return 0;
}
