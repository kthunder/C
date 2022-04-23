/*#include<stdio.h>
int main()
{
    int n, k;
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    scanf("%d", &k);
    int seek[k];
    int result[k];
    for (int i = 0; i < k; i++)
    {
        result[i] = 0;
    }
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &seek[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (seek[j] == array[i])
            {
                result[j] += 1;
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        printf("%d", result[i]);
        if (i != k-1)
        {
            printf(" ");
        }
    }
}*/
#include<stdio.h>

int main(int argc, char const *argv[])
{
    int hashtab[101] = {0};
    int n, k;
    int temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        hashtab[temp]++;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &temp);
        printf("%d", hashtab[temp]);
        if (i != k-1)
            putchar(' ');
    }
    return 0;
}
