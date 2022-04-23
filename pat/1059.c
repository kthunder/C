#include<stdio.h>

int isPrime(int x)
{
    if (x == 1)
        return 0;

    for (size_t i = 2; i*i <= x; i++)
    {
        if(x%i == 0)
            return 0;
    }
    return 1;
}

int search(int id,int rank[],int len)
{
    for (size_t i = 1; i <= len; i++)
        if (id == *(rank+i))
            return i;

    return 0;
}

void award(int x,int flag)
{
    if (flag == -1&&x!=0)
    printf("Checked\n");
    else if (x == 0)
        printf("Are you kidding?\n");
    else if (x == 1)
        printf("Mystery Award\n");
    else if(isPrime(x))
        printf("Minion\n");
    else
        printf("Chocolate\n");
}

int main(int argc, char const *argv[])
{
    int num;
    int temp;
    int toSearch;
    scanf("%d", &num);
    int rank[num + 1];
    int tab[num + 1] ;
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &rank[i + 1]);
        tab[i + 1] = 0;
    }

    scanf("%d", &temp);
    for (size_t i = 0; i < temp; i++)
    {
        int a;
        scanf("%d", &toSearch);
        printf("%04d: ", toSearch);
        a = search(toSearch, rank, num);
        award(a,tab[a]);
        tab[a] = -1;
    }


    return 0;
}
