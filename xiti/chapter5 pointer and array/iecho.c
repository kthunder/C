#include<stdio.h>
/*1st version
int main(int argc, char const *argv[])
{
    int i;

    for ( i = 0; i < argc; i++)
    {
        printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
    }
    printf("\n");
    return 0;
}*/

int main(int argc, char const *argv[])
{
    while (--argc > 0)
    {
        printf("%s%s", *++argv, (argc > 1) ? " " : "");
    }
    printf("\n");
    return 0;
}

