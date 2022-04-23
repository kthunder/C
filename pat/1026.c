#include<stdio.h>
int main()
{
    long c1,c2;
    long time;
    long hours,mins,secs;
    scanf("%ld %ld",&c1 ,&c2);
    time = ((c2 - c1)+50)/100;
    hours = time/3600;
    mins = (time%3600)/60;
    secs = (time%3600)%60;
    printf("%02ld:%02ld:%02ld\n",hours,mins,secs);
}