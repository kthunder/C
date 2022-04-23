#include<stdio.h>

int main(int argc, char const *argv[])
{
    char str1[128] = {0};
    char str2[128] = {0};
    char c;
    int lack = 0;
    int redundant = 0;
    while((c = getchar())!='\n')
    {
        str1[c] += 1;
    }
    while((c = getchar())!='\n')
    {
        str2[c] += 1;
    }
    for (int i = 0; i < 128; i++)
    {
        if (str2[i]!=0)
        {
            if(str1[i] - str2[i] < 0)
                lack += -(str1[i] - str2[i]);
        }
    }
    if (lack > 0)
    {
        printf("No %d", lack);
        return 0;
    }
    else
    {
        for (int i = 0; i < 128; i++)
        {
            redundant += str1[i] - str2[i];
        }
        printf("Yes %d",redundant);
        return 0;
    }

}
