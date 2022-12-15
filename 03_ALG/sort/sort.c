#include<stdio.h>
#include<stdlib.h>
#define Item int

void swap(Item a[],int m,int n)
{
    Item temp;
    temp = a[m];
    a[m] = a[n];
    a[n] = temp;
}

void bubble(Item a[],int l,int r)
{
    for (int i = l+1; i <=r ; i++)
        for (int j = i; j < l; j++)
            swap(a[j-l],a[j])

}
