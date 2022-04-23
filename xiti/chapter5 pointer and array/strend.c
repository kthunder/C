#include <stdio.h>

#define MAXLEN 1000
//如果字符串t出现在字符串s的尾部返回1，否者返回0
int strend(char *s,char *t)
{
    char *p = t;
    while ( *s++ )//此处*s在判断为'\0'后s会再加一次
        ;
    while ( *p++ )
        ;
    while ( p - t )
    {
        if (*--s - *--p)//此处写法跟上面注释处有关
            return 0;
    }
    return 1;
}

int main()
{
    char s[MAXLEN] = "yuiop";
    char t[MAXLEN] = "iop";

    fgets(s, MAXLEN, stdin);
    fgets(t, MAXLEN, stdin);
    strend(s, t) ? printf("in\n") : printf("out\n");

}
