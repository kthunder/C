#include<stdio.h>
int isEqual(int number)
{
    if(number==0)
    {
        printf("0000 - 0000 = 0000\n");
        return 1;
    }
    else if (number/1111>0&&number/1111<10&&number%1111 == 0)
    {
        printf("%04d - %04d = 0000\n",number,number);
        return 1;
    }
    else
    {
        return 0;
    }
    
    
}
int NonIncremental(int number)//非递增排序
{
    int array[4];
    int temp = number;
    int x=1000;
    for (int i = 0; i < 4; i++)
    {
        array[i] = temp/x;
        temp = number%x;
        x/=10;
    }
    for (int j = 3; j >0; j--)
    {
        for (int i = 0; i < j; i++)
        {
            int t;
            if (array[i]<array[i+1])
            {
                t = array[i+1];
                array[i+1] = array[i];
                array[i] = t;
            }
            
        }
    }
    
    
    //printf("%d\n",array[0]*1000+array[1]*100+array[2]*10+array[3]);
    return (array[0]*1000+array[1]*100+array[2]*10+array[3]); 
}
int NonDecreasing(int number)//非递减排序
{
    int array[4];
    int temp = number;
    int x=1000;
    for (int i = 0; i < 4; i++)
    {
        array[i] = temp/x;
        temp = number%x;
        x/=10;
    }
    for (int j = 3; j >0; j--)
    {
        for (int i = 0; i < j; i++)
        {
            int t;
            if (array[i]>array[i+1])
            {
                t = array[i+1];
                array[i+1] = array[i];
                array[i] = t;
            }
            
        }
    }
    return (array[0]*1000+array[1]*100+array[2]*10+array[3]); 
}

int main()
{
    int num;
    scanf("%d",&num);
    do
    {
        if (isEqual(num))
        {
            break;
        }
        
        printf("%04d - %04d = %04d\n",NonIncremental(num),NonDecreasing(num),NonIncremental(num)-NonDecreasing(num));
        num = NonIncremental(num)-NonDecreasing(num);
    } while (num != 6174); 
}

