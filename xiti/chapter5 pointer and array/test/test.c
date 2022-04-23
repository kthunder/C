#include<stdio.h>

//平年和闰年每月天数
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
    leap = isLeapYear(year);
    if(year<1||(month>12||month<1)||day>daytab[leap][month])
    {
        printf("wrong date");
        return -1;
    }
    for (size_t i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

int main()
{
    int bDay, bMonth, bYear;
    int nDay, nMonth, nYear;
    int totalDays = 0;
    printf("please input your birthday format:yy mm dd\n");
    scanf("%d %d %d", &bYear, &bMonth, &bDay);
    printf("please input current date format:yy mm dd\n");
    scanf("%d %d %d", &nYear, &nMonth, &nDay);
    for (int i = bYear; i < nYear; i++)
    {
        totalDays += isLeapYear(i) ? 366 : 365;
    }
    totalDays = totalDays + day_of_year(nYear, nMonth, nDay) - day_of_year(bYear,bMonth,bDay) + 1;
    printf("you have survival %d days", totalDays);
}

