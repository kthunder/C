#include <stdio.h>
/*
G = 17S
S = 29K
*/

int sum(int array[])
{
    return (array[0]*17+array[1])*29+array[2];
}

int main(int argc, char const *argv[])
{
    int pay[3] = {0};
    int price[3] = {0};
    int change = 0;
    scanf("%d.%d.%d" ,&price[0], &price[1], &price[2]);
    scanf("%d.%d.%d" ,&pay[0], &pay[1], &pay[2]);

    change = sum(pay) - sum(price) ;

    if (change<0)
    {
        printf("-");
        change *= -1;
    }
    printf("%d.%d.%d", change / 29 / 17, change / 29 % 17, change % 29);

    return 0;
}
