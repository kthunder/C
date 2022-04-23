#include <stdio.h>
#include <string.h>
void reverse(char *str,int min,int max);

int main()
{
    char s[20] = "wanshulin";
    scanf("%s", s);
    reverse(s, 0, strlen(s) - 1);
    printf("%s", s);
    return 0;
}

void reverse(char *str,int min,int max)
{
    if (min < max)
    {
        char temp;
        temp = str[min];
        str[min] = str[max];
        str[max] = temp;
        reverse(str, ++min, --max);
    }

}
