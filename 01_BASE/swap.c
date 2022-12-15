#include <stdio.h>

#define swap(t, x, y) \
    {t temp;           \
    temp = x;         \
    x = y;            \
    y = temp;}



int main()
{
    char x=123, y=125;


    //scanf("%d %d", &x, &y);
    swap(int, x, y);
    printf("x = %3d, y = %3d\n", x, y);
    swap(int, x, y);
    printf("x = %3c, y = %3c\n", x, y);
}
