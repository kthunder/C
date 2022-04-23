#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    struct student
    {
        char name[11];
        char number[11];
        int score;
    };
    struct student max,min,temp;
    max.score = -1;
    min.score = 101;
    for (int y = 0; y < n; y++)
    {
        scanf("%s %s %d",temp.name ,temp.number,&temp.score);
        if(temp.score >= max.score)
        {
            //printf("%d",temp.score);
            for (int i = 0; i < 11; i++)
            {
                max.name[i] = temp.name[i];
                max.number[i] = temp.number[i];
            }
            max.score = temp.score;
        }
        if(temp.score <= min.score)
        {
            for (int i = 0; i < 11; i++)
            {
                min.name[i] = temp.name[i];
                min.number[i] = temp.number[i];
            }
            min.score = temp.score;
        }
    }
    printf("%s %s\n",max.name ,max.number);
    printf("%s %s",min.name ,min.number);
    
}
