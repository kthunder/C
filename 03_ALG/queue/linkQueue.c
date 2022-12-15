#include<stdio.h>
#include<stdlib.h>

typedef int QItem;

typedef struct qnode *qlink;
struct qnode
{
    QItem element;
    qlink next;
} Qnode;//定义节点

typedef struct lque *Queue;
typedef struct lque{
    qlink front;//头指针
    qlink rear;//尾指针
} Lqueue;

/*队列的6个基本运算*/
int QueueFull(Queue Q);
int QueueEmpty(Queue Q);
QItem QueueFirst(Queue Q);
QItem QueueLast(Queue Q);
void EnterQueue(QItem x,Queue Q);
QItem DeleteQueue(Queue Q);

Queue QueueInit()
{
    Queue Q = malloc(sizeof *Q);
    Q->front = Q->rear = NULL;
    return Q;
}

int QueueEmpty(Queue Q)
{
    return Q->front == 0;
}

int QueueFull(Queue Q)
{
    return QmemFull();
}

int QmemFull()
{
    qlink p;
    if ((p = malloc(sizeof(Qnode))) == 0)
        return 1;
    else
    {
        free(p);
        return 0;
    }
}

QItem QueueFirst(Queue Q)
{
    if (QueueEmpty(Q))
        printf("Queue is Empty");
    else
        return Q->front->element;
}

QItem QueueLast(Queue Q)
{
    if (QueueEmpty(Q))
        printf("Queue is Empty");
    else
        return Q->rear->element;
}

void EnterQueue(QItem x,Queue Q)
{
    qlink p;
    p = NewQNode();
    p->element = x;
    p->next = 0;

    if (Q->front)
        Q->rear->next = p;
    else
    {
        Q->front = p;
        Q->rear = p;
    }
}
/*删除并返回首个节点元素，将头指针指向下一个节点*/
QItem DeleteQueue(Queue Q)
{
    qlink p;
    QItem x;
    if (QueueEmpty(Q))
        printf("queue is Empty");
    x = Q->front->element;
    p = Q->front;
    Q->front = Q->front->next;
    free(p);
    return x;
}
