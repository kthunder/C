#include<stdio.h>

struct person
{
    char name[10];
    int year;
    int month;
    int day;
};

int camp(struct person a,struct person b);
int camp2(struct person a, struct person b);

int main(int argc, char const *argv[])
{
    int n;
    int count = 0;
    struct person left = {"left",2014-200, 9, 6};
    struct person right = {"right",2014, 9, 6};
    struct person oldest, youngest, temp;
    youngest = left;
    oldest = right;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d/%d/%d", temp.name, &temp.year, &temp.month, &temp.day);
        if (camp(temp,right) || camp2(temp,left))
            continue;
        else
        {
            count++;
            youngest = (camp(temp, youngest) ? temp : youngest);
            oldest = (camp(temp, oldest) ? oldest : temp);
        }

    }
    if (count != 0)
        printf("%d %s %s", count, oldest.name, youngest.name);
    else
        printf("0");

    return 0;
}

int camp(struct person a,struct person b)
{
    if (a.year != b.year)
        return a.year > b.year;
    else if(a.month != b.month)
        return a.month > b.month;
    else
        return a.day > b.day;
}

int camp2(struct person a,struct person b)
{
    if (a.year != b.year)
        return a.year < b.year;
    else if(a.month != b.month)
        return a.month < b.month;
    else
        return a.day < b.day;
}
