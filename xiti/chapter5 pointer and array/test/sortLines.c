#include<stdio.h>
#include<string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];
char stringarray[10 * MAXLINES];

int readlines(char *lineptr[],int maxlines);
void writelines(char *lineptr[],int maxlines);

void qsort(char *lineptr[],int left,int right);

int main(int argc, char const *argv[])
{
    int nlines = 10;

    if ((nlines = readlines(lineptr,MAXLINES))>=0)
    {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }else
    {
        printf("error: read lines too big to sort");
        return 1;
    }
}

#define MAXLEN 1000
int getline(char *string, int maxlen){
    char *p = string;
    char ch;
    while (--maxlen > 0&& (ch = getchar())!=EOF&&ch!='\n')
    {
        *string++ = ch;
    }
    if (ch == '\n')
    {
        *string++ = ch;
    }
    *string = '\0';
    return string-p;
}


int readlines(char *lineptr[],int lines)
{

    char *pStar,*pStop;
    pStop = stringarray;
    for (size_t i = 0; i < lines; i++)
    {
        pStar = pStop;
        lineptr[i] = pStar;
        pStop += (getline(pStar, MAXLEN)+1);
    }
    return 0;
}
void writelines(char *lineptr[],int maxlines)
{

    for (size_t i = 0; i < maxlines; i++)
    {
        printf("%s", lineptr[i]);
    }

}

