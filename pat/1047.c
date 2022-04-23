#include<stdio.h>

int main(int argc, char const *argv[])
{
    int n,team,menber,point;
    int array[1001] = {0};
    int max;
    int temp = -1;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d-%d %d", &team, &menber, &point);
        array[team] += point;
    }
    for (int i = 0; i <= 1001; i++)
    {
        if (array[i] > temp )
        {
            temp = array[i];
            max = i;
        }

    }
    printf("%d %d", max, temp);
    return 0;
}
