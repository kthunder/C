#include <stdio.h>

int main(int argc, char const *argv[])
{
    int m, n;
    scanf("%d %d", &n, &m);
    int score[m];
    int answer[m];
    for (int i = 0; i < m; i++)
        scanf("%d", &score[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &answer[i]);

    for (size_t i = 0; i < n; i++)
    {
        int flag = 0;
        int sum = 0;
        for (size_t j = 0; j < m; j++)
        {
            scanf("%d", &flag);
            if (flag == answer[j])
            {
                sum += score[j];
            }

        }
        printf("%d\n", sum);
    }

    return 0;
}
