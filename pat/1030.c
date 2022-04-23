#include <stdio.h>

int main()
{
    //int max, min;
    long long n, temp, p;
    scanf("%lld %lld", &n, &p);
    long long array[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &array[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
            
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        if (array[i]*p >= array[n])
        {
            printf("%lld", n - i);
            break;
        }
        
    }
    
    
}