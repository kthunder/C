#include<stdio.h>
#include<ctype.h>
int main(int argc, char const *argv[])
{
    int tab[128] = {0};
    char c;
    int temp = 0;
    int max;
    while ((c = getchar())!= '\n')
    {
        if (isalpha(c))
        {
            tab[tolower(c)]++;
        }
    }
    for (int i = 'a'; i <= 'z'; i++)
    {
        if (tab[i] > temp)
        {
            temp = tab[i];
            max = i;
        }
    }
    printf("%c %d", max,tab[max]);
    return 0;
}
