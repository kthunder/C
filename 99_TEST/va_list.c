#include <stdarg.h>
#include <stdio.h>
 
void fun(int a,...)
{
    va_list pp;
    int n=1;
    va_start(pp,a);
    do
    {
        printf("第 %d 个参数 =%d\n",n++,a);
        a=va_arg(pp,int);
    }
    while (a!=0);
    va_end(pp);
}
 
int main()
{
    fun(20,40,60,80,0);
    return 0;
}