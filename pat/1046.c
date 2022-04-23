#include<stdio.h>

int main()
{
    int a ,b ,jia ,yi;
    int J = 0,Y = 0;
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d",&a, &jia ,&b, &yi);
        if (a + b == jia && a + b != yi)
        {
            Y++;
        }
        else if (a + b != jia && a + b == yi)
        {
            J++;
        }
        
    }
    printf("%d %d\n",J,Y );
}