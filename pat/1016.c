#include<stdio.h>

int main()
{
    int Da,Db;
    int Pa = 0,Pb = 0;
    int j = 1,k = 1;
    char A[10],B[10];
    scanf("%s %d %s %d",A,&Da,B,&Db);
    for (int i = 0; A[i] != '\0'; i++)
    {
        if (A[i] == Da+48)
        {
            Pa = Pa + j;
            j*=10;
        }
        
    }
    Pa = Pa*Da;
    for (int i = 0; B[i] != '\0'; i++)
    {
        if (B[i] == Db+48)
        {
            Pb = Pb + k;
            k*=10;
        }
        
    }
    Pb = Pb*Db;
    printf("%d",Pa+Pb);
}