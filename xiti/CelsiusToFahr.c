#include <stdio.h>

#define lower 0
#define upper 300
#define step 20

int main()
{
    int fahr;
    printf("Fahr  Celsius\n");
    for (fahr = lower; fahr <= upper; fahr = fahr + step)
    {
        printf("%3d  %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }

    return 0;
}
