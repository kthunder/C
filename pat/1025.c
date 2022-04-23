#include <stdio.h>

typedef struct node
{
    int address;
    int data;
    int next;
    int order;
} node;

int main()
{
    int firstadress;
    int adress;
    int count = 0;
    int n;
    int k;
    int temp;
    scanf("%d %d %d", &firstadress, &n, &k);
    temp = firstadress;
    node list[100000];
    for (int i = 0; i < 100000; i++)
    {
        list[i].data = 0;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &adress);
        list[adress].address = adress;
        scanf("%d %d",  &list[adress].data, &list[adress].next);
    }
    for (int i = 1; list[temp].data!=0 ; i++)
    {
        list[temp].order = i;
        temp = list[temp].next;
        count++;
    }
    node list2[count];
    temp = firstadress;
    for (int i = 0; i < count; i++)
    {
        list2[i] = list[temp];
        temp = list[temp].next;
    }
