#include<stdio.h>
#include<ctype.h>
int getid(int *id)
{
    char c;
    getchar();
    for (int i = 0; i < 18; i++)
    {
        while (isspace(c = getchar()))
            ;
        if (isdigit(c))
            id[i] = c - '0';
        else
            id[i] = c;
    }
    return 0;
}
int judge(int id[])
{
    for (int i = 0; i < 17; i++)
        if (id[i]>9 || id[i]<0)
            return 0;
    return 1;
}

int getz(int id[])
{
    int sum = 0;
    int wight[17] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    for (int i = 0; i < 17; i++)
        sum += (id[i] * wight[i]);
    return sum%11;
}
int main()
{
    int id[18];
    int m[11] = {1 ,0 ,'X' ,9 ,8 ,7 ,6 ,5 ,4 ,3 ,2 };
    int n;
    int count = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        getid(id);
        if (!judge(id) || m[getz(id)] != id[17])
        {
            count++;
            for (int j = 0; j < 18; j++)
            {
                if (id[j] == 88)
                    printf("X");
                else
                    printf("%d", id[j]);
                if(j == 17)
                    printf("\n");
            }
        }
    }
    if(count == 0)
        printf("All passed");
    return 0;
}
