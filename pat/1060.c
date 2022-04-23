#include<stdio.h>
#include<stdlib.h>

int compare(const void* a,const void* b)
//比较函数，传入const void指针，返回值为int；
{
    return *(int *)a - *(int *)b;
}

int main(int argc, char const *argv[])
{
    int n;
    int e = 0;
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    qsort(array, n, sizeof(int), compare);
    for (int i = 0; i < n; i++)
    {
        if (array[i] > n-i)
        {
            e = n - i;
            break;
        }
        //printf("%d ", array[i]);
    }
    printf("%d", e);
    return 0;
}
