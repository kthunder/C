#include<stdio.h>
int main()
{
    int n;
    int x,score;
    int max,maxx,len = 0;
    scanf("%d",&n);
    int sum[100005]={0,};
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d",&x,&score);
        sum[x] += score;
        if(x>len)
            len = x;
    }
    max = sum[1];
    maxx = 1;
    for (int i = 1; i < len; i++)
    {
        if (max<sum[i+1])
        {
            max = sum[i+1];
            maxx = i+1;
        }        
    }
    
    printf("%d %d",maxx,max);

}