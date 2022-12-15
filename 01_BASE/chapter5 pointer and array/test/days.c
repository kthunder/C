#include<stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int isLeapYear(int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int day_of_year(int year,int month,int day)
{
    int leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if(year<1||(month>12||month<1)||day>daytab[leap][month])
    {
        return -1;
    }
    for (size_t i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}
void month_day(int year,int yearday,int *pmonth,int *pday)
{
    int i,leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if (yearday<1||(leap == 0 && yearday > 365) || (leap == 1 && yearday >365))
    {
        *pmonth = -1;
        *pday = -1;
    }

    for (i = 0; yearday>daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

int main(int argc, char const *argv[])
{
    int inYear, inMonth, inDay;
    int tempMonth, tempDay;
    int days;
    scanf("%d-%d-%d", &inYear, &inMonth, &inDay);
    printf("%d\n", days = day_of_year(inYear, inMonth, inDay));
    month_day(inYear, days, &tempMonth, &tempDay);
    if (tempMonth != inMonth || tempDay != inDay)
    {
        printf("fail");
    }else
    {
        printf("succeed");
    }



    return 0;
}
