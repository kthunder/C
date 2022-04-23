#include<stdio.h>
#include <stdlib.h>
struct students
{
    int number;
    int descore;
    int caiscore;
    int sum;
};
int mycmp(const void *a, const void *b) 
{
    struct students A = *(struct students *) a;
    struct students B = *(struct students *) b;
    if (B.sum == A.sum) 
    {
        if (B.descore == A.descore) 
        {
            return A.number - B.number;
        } else 
        {
            return B.descore - A.descore;
        }
    } 
    else 
    {
        return (B.sum) - (A.sum);
    }
}
int main()
{
    int n,bline,aline;
    int number,descore,caiscore,count = 0;
    scanf("%d %d %d",&n,&bline,&aline);
    struct students studentsarray[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d",&number,&descore,&caiscore);
        if(descore>=aline && caiscore>=aline)
        {
            studentsarray[count] = (struct students){number,descore,caiscore,(descore + caiscore)*4};
            count++;
        }
        else if(descore>=aline && caiscore<aline&&caiscore>=bline)
        {
            studentsarray[count] = (struct students){number,descore,caiscore,(descore + caiscore)*3};
            count++;
        }
        else if(descore<aline && caiscore<aline&&caiscore>=bline&&descore>=bline&&descore>=caiscore)
        {
            studentsarray[count] = (struct students){number,descore,caiscore,(descore + caiscore)*2};
            count++;
        }
        else if(caiscore>=bline&&descore>=bline&&descore<caiscore)
        {
            studentsarray[count] = (struct students){number,descore,caiscore,(descore + caiscore)};
            count++;
        }
    }
    qsort(&studentsarray[0], count, 16, mycmp );
    printf("%d\n",count);
    for (int j = 0; j < count; j++)
    {
        printf("%d %d %d\n", studentsarray[j].number, studentsarray[j].descore, studentsarray[j].caiscore);
    }
    return 0;               
}