#include<stdio.h>
 int main()
 {
    char str[1001];
    int array[10] = {0,};
    scanf("%s",str);
    for (int i = 0; str[i]!='\0'; i++)
    {
        array[str[i] - 48]++;
    }
    for (int i = 0; i < 10; i++)
    {
        if(array[i]!=0)
            printf("%d:%d\n",i,array[i]);
    }
    
 }