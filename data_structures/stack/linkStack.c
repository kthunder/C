#include<stdio.h>
#include<stdlib.h>
typedef int StackItem;
typedef struct snode *slink;
typedef struct snode
{
    StackItem element;
    slink next;
} StackNode;

slink NewStackNode()
{
    slink p;
    if (p = malloc(sizeof(StackNode)) == 0)
        printf("exhausted memory");
    else
        return p;
}

typedef struct lstack *Stack;
typedef struct lstack
{
    slink top;//栈顶节点指针；
} Lstack;

Stack StackInit()
{
    Stack S = malloc(sizeof *S);
    S->top = 0;
    return S;
}

int StackEmpty(Stack S)
{
    return S->top == 0;
}

int StackMemFull()
{
    slink p;
    if ((p = malloc(sizeof(StackNode)))==0)
        return 1;
    else
    {
        free(p);
        return 0;
    }
}

int StackFull(Stack S)
{
    return StackMemFull();
}

StackItem StackTop(Stack S)
{
    if (StackEmpty(S))
        printf("stack is empty");
    else
        return S->top->element;
}

void Push(StackItem x,Stack S)
{
    slink p;
    if (StackFull(S))
        printf("stack is full");
    p = NewStackNode();
    p->element = x;
    p->next = S->top;
    S->top = p;
}

StackItem Pop(Stack S)
{
    slink p;
    StackItem x;
    if (StackEmpty(S))
        printf("stack is empty");
    x = S->top->element;
    p = S->top;
    S->top = p->next;
    free(p);
    return x;
}
