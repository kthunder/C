#include <stdio.h>

void itoa(long long int n, char *str)
{
    static int i = 0;
    if (n < 0)
    {
        n *= -1;
        str[i++] = '-';
    }
    if (n > 10)
    {
        itoa(n / 10, str);
    }
    str[i++] = (n % 10 + '0');
    str[i] = '\0';
}

int main()
{
    char str[20];
    long long int n = 456;
    scanf("%ld", &n);
    itoa(n, str);
    printf("%s", str);
    return 0;
}
