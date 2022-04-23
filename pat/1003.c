#include<stdio.h>
#include<string.h>
int judge(char *str)
{
    int lenth = strlen(str);
    int countP = 0;
    int countT = 0;
    int countA = 0;
    int countX = 0;
    int middleA = 0;
    for (int i = 0; i < lenth; i++)
    {
        if      (*(str+i) == 'P')
            countP++;
        else if (*(str+i) == 'A')
        {    
            countA++;
            if(countP == 1&&countT != 1)
                middleA++;
        }
        else if (*(str+i) == 'T')
            countT++;
        else
            countX++;   
    }
    if (countT > 1||countP > 1||countA == 0||countX != 0||middleA>2)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
    }
    return 0;
}

int main()
{
    int n;
    char c[100];
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s",c);
        judge(c);
    }
    return 0;
}