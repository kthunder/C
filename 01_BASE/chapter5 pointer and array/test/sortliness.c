#include<stdio.h>
#include<string.h>
#define MAXLEN 100//每行读取的字符串最大长度
#define MAXLINES 100//读取的字符串最大行数


char *lineptr[MAXLINES] = {0};//储存字符串头指针的数组
char charvalue[MAXLEN * MAXLINES] = {0};//储存所有字符串的数组

/*读取一行字符串到字符数组中，返回字符串长度*/
int getline(char *string, int maxlen){
    char *p = string;
    char ch;
    while (--maxlen > 0 && (ch = getchar())!=EOF && ch!='\n')
    {
        *string++ = ch;
    }
    if (string-p>0)
    {
        *string++ = '\n';
    }
    *string = '\0';
    return string-p;
}

int readlines(char *lineptr[],int maxlines)
{
    int count = 0;
    int len;
    char *pStar,*pStop;
    pStop = charvalue;
    for (size_t i = 0; i < maxlines; i++)
    {
        pStar = pStop;
        if((len = getline(pStar, MAXLEN))>0)
        {
            lineptr[count] = pStar;
            pStop += (len+1);
            count++;
        }else
        {
            break;
        }
    }
    return count;
}

void writelines(char *lineptr[],int maxlines)
{
    for (size_t i = 0; i < maxlines; i++)
    {
        printf("%s", lineptr[i]);
    }
}

void swap(char *v[], int i, int j)
{
	char *temp = NULL;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void myqsort(char *v[], int left, int right)
{
	int i = 0;
	int last = 0;

	if (left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	myqsort(v, left, last-1);
	myqsort(v, last+1, right);
}

int main()
{
    int count = 0;
    if ((count = readlines(lineptr,MAXLINES))>0&&count<=10)
    {
        myqsort(lineptr, 0,count-1);
        writelines(lineptr, count);
    }
    else
    {
        printf("error: read lines too big to sort");
    }

    return 0;
}
