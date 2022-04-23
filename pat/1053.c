#include<stdio.h>

int main()
{
    int n, d;
    double e;
    scanf("%d %lf %d", &n, &e, &d);
    int mayempty = 0, empty = 0;
    for (int i = 0; i < n; i++)
    {
        int day = 0, k;
        double temp;
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%lf", &temp);
            if (temp < e)
            {
                day++;
            }
        }
        if (day*2 > k && k > d) //是观察天数大于阈值！
        {
            empty++;
        }
        else if (day*2 > k)
        {
            mayempty++;
        }
    }
    printf("%.1f%% %.1f%%", mayempty * 100.0 / n , empty * 100.0 / n );
    return 0;
}
