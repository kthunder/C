#include <stdio.h>

int int_to_pinyin(int n)
{
    char py[10][4]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    for (int i = 0; i < 4; i++)
    {    
        if(py[n][i] != 0)
            printf("%c",py[n][i]);
    }
    return 0;
}

int main()
{
    int x,last_number;
    int sum = 0;
    int py[3] = {0,0,0};
    int i = 0;
    while ((x = getchar()) != 10)
       sum = sum + (x-48);
    while(sum != 0)
    {
        last_number = sum % 10;
        py[i] = last_number;
        
        i++;
        
        sum = sum / 10;
    }
    
    for (i = i - 1; i >=0; i--)
    {
        int_to_pinyin(py[i]);
        //printf("%d",i);
        if(i != 0)
            printf(" ");
    }
    
    
}