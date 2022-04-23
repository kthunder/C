#include<stdio.h>
int main()
{
    char *day[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    char str1[61];
    char str2[61];
    char str3[61];
    char str4[61];
    int days,hours,mins,count=0;
    scanf("%s %s %s %s", str1, str2, str3, str4);
    for (int i = 0; i < 61; i++)
    {
        if(str1[i]==str2[i]&&str1[i]>='A'&&str1[i]<='G'&&count==0)
        {    
            days = str1[i] - 64;
            count++;
        }
        else if(str1[i]==str2[i]&&str1[i]>='A'&&str1[i]<='N'&&count==1)
        {
            hours = str1[i] - 64+9;
            count++;
        }
        else if(str1[i]==str2[i]&&str1[i]>='0'&&str1[i]<='9'&&count==1)
        {
            hours = str1[i] - 48;
            count++;
        }
    }
    for (int i = 0; i < 61; i++)
    {
        if(str3[i]==str4[i]&&str3[i]>='A'&&str4[i]<='Z')
        {    
            mins = i;
            break; 
        }
        if(str3[i]==str4[i]&&str3[i]>='a'&&str4[i]<='z')
        {    
            mins = i;
            break; 
        }
    }
    printf("%s %02d:%02d",day[days-1],hours,mins);
}