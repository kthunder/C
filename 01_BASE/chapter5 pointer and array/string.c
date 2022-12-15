#include <stdio.h>

/* strcpy:  copy t to s; array subscript version */
int strlen(char *s)
{
    char *p = s;

    while( *p++ )
        ;
    return p - s;
}

/*
v1
 strcpy:  copy t to s; pointer version
void strcpy(char *s , char *t)
{
    while ((*s = *t)!= '\0')
    {
        s++;
        t++;
    }
}
v2
void strcpy(char *s , char *t)
{
    while ((*s++ = *t++) != '\0')
        ;
}
v3
 */
void strcpy(char *s , char *t)
{
    while (*s++ = *t++)
        ;
}

void my_strcpy(char *s , char *t, int n)
{
    while (*s++ = *t++)
        ;
}




/* strcmp:  return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp(char *s ,char *t)
{
    for (;*s == *t  ; s++,t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}



/*进栈出栈的标准用法
*p++ = value ;
value = *--P;*/

//将t复制到s尾部
void strcat(char *s ,char *t)
{
    while (*s)
        s++;
    while (*s++ = *t++)
        ;
}

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
    char s[50] = "qwertyuiop";
    char t[10] = "iop";
    char r[10] = "iwqdj";
    scanf("%s", s);
    scanf("%s", t);
    scanf("%s", r);
    strcat(s, t);
    strcat(s, r);
    printf("%s\n", s);

}
