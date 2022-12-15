#include<stdio.h>
/*
用指针将存储表元素的那些单元依次串联在一起。这种方法避免了在数组中用连续的单元存储元素的缺点，因而在执行插入或删除运算时，不再需要移动元素来腾出空间或填补空缺。然而为此付出的代价是，需要在每个单元中设置指针来表示表中元素之间的逻辑关系，因而增加了额外的存储空间开销。为了将存储表元素的所有单元用指针串联起来，让每个单元包含一个元素和一个指针，其中指针指向表中下一个元素所在的单元。
*/
typedef int ListItem;//表的成员类型
typedef struct node *link;//指向节点的指针
typedef struct node
{
    ListItem element;
    link next;
}Node;

link NewNode(viod)//申请一个新节点，并返还指向该节点的指针
{
    link p;
    if((p = malloc(sizeof(Node))) == 0)
        Error("Exhausted memory");
    else
        return p;
}

typedef struct list *List;//指向struct list的指针
typedef struct list
{
    link first;//指向第一个节点的指针
}List;

List* ListInit(void)
{
    List *L = malloc(sizeof(List));
    L->first = NULL;
    return L;
}

