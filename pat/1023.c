#include <stdio.h>

int main()
{
    int array[10]= {0,},a;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a);
        array[i] = a;
    }
    // for (int i = 0; i < 10; i++)
    // {
    //     if (array[i]!=0)
    //     printf("%d %d\n", i, array[i]);
    // }
    for (int i = 1; i < 10; i++)
    {
        if (array[i]!=0)
        {
            printf("%d", i);
            array[i] -= 1;
            break;
        }
        
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < array[i]; j++)
        {
            printf("%d", i);
        }        
    }
    
}
