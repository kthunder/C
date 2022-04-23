#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include"getword.c"

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(struct key))

struct key{
    char *word;
    int count;
} keytab[NKEYS];

int getword(char *, int);

int binsearch(char *, struct key *, int);

int main(int argc, char const *argv[])
{
    int n;
    char word[MAXWORD];

    while (getword(word,MAXWORD) != EOF)
    {
        if (isalpha(word[0]))
        {
            if((n = binsearch(word,keytab,NKEYS)) >= 0)
                printf("%4d %s\n", keytab[n].count, keytab[n].word);
        }

    }

    return 0;
}

