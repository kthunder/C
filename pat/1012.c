#include<stdio.h>
int main()
{
    int n,x;
    int flag = 1;
    int count = 0;
    int count2 = 0;
    int array[5] = {0,};
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&x);
        if(x%5 == 0&&x%2 == 0)
        {
            array[0] += x;
        }
        else if (x%5 == 1)
        {
            array[1] = array[1] + flag*x;
            flag *= (-1);
            count2++;
        }
        else if (x%5 == 2)
        {
            array[2] ++;
        }
        else if (x%5 == 3)
        {
            array[3] += x;
            count++;
        }
        else if (x%5 == 4)
        {
            if(array[4]<x)
                array[4] = x;
        }
        
        
        

    }
    for (int i = 0; i < 5; i++)
        {
            if (i!=3)
            {
                
                if (i == 1 && count2 != 0)
                {
                    printf("%d",array[i]);
                }
                else if(array[i]!=0)
                    printf("%d",array[i]);
                else
                    printf("N");
                //printf("\n");
            }
            else 
            {
                if(array[i]!=0)
                    printf("%.1f",((float)array[i])/(float)count);
                else
                    printf("N");
                //printf("\n");
            }
            
            if(i!=4)
                printf(" ");
            
        }

}