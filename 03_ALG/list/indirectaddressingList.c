/*
间接寻址方法是将数组和指针结合起来实现表的一种方法。
它将数组中原来存储元素的地
方改为存储指向元素的指针
*/
#include<stdio.h>
#include<stdlib.h>
typedef int ListItem;//先设定元素类型为int
typedef ListItem *addr;
typedef struct indlist *List;
typedef struct indlist
{
    int n;//表的长度
    int maxsize;//表的最大长度
    addr *table;//指向表中元素的指针数组
} Indlist;

List ListInit(int size)
{
    List L = malloc(sizeof *L);
    L->n = 0;
    L->maxsize = size;
    L->table = malloc(size * sizeof(addr));//addr的类型是指向元素指针
    return L;
}//分配空间，初始化一个表

int ListEmpty(List L)
{
    return L->n == 0;
}//测试表是否为空表

int ListLength(List L)
{
    return L->n;
}//返回表的长度

ListItem ListRetrieve(int k,List L)
{
    if (k<1 || k>L->n)
        printf("out of bounds");
    return *L->table[k - 1];
}//返回表k处元素

int ListLocate(ListItem x,List L)
{
    for (int i = 0; i < L->n; i++)
        if (*L->table[i] == x)
            return ++i;
    return 0;
}

void ListInsert(int k,ListItem x,List L)
{
    if (k<1 || k>L->n)
        printf("out of bounds");
    if (L->n == L->maxsize)
        printf("out of memory");
    for (int i = L->n-1; i>=k; i--)
        L->table[i + 1] = L->table[i];//把位置k后的元素向后移动一位；
    L->table[k] = NewNode();//为新元素申请空间，并返回空间的指针给k位置
    *L->table[k] = x;
    L->n++;//表长加1
}

ListItem ListDelete(int k,List L)
{
    ListItem x;
    addr p;
    if (k<1 || k>L->n)
        printf("out of bounds");
    p = L->table[k - 1];//取k-1位置的指针
    x = *p;//将k-1位置的指针指向的元素赋值给x，最后作为返回值
    for (int i =k; i <L->n; i++)
        L->table[i - 1] = L->table[i];//元素向前移动一位
    free(p);
    L->n--;
    return x;
}

void PrintList(List L)
{
    for (int i = 0; i < L->n; i++)
        ItemShow(*L->table[i]);//打印元素
}
