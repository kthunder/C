#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node;

typedef struct queue {
    node* head;
    node* tail;
    pthread_mutex_t headLock;
    pthread_mutex_t tailLock;
} queue;

void queue_init(queue* q)
{
    node* tmp = malloc(sizeof(node));
    tmp->next = NULL;
    q->head = q->tail = tmp;
    pthread_mutex_init(&q->headLock, NULL);
    pthread_mutex_init(&q->tailLock, NULL);
}

void queue_enqueue(queue* q, int value)
{
    node* tmp = malloc(sizeof(node));
    assert(tmp != NULL);

    tmp->val = value;
    tmp->next = NULL;

    pthread_mutex_lock(&q->tailLock);
    q->tail->next = tmp;
    q->tail = tmp;
    pthread_mutex_unlock(&q->tailLock);
}

int queue_dequeue(queue* q, int* value)
{
    pthread_mutex_lock(&q->headLock);
    node* tmp = q->head;
    node* newNode = tmp->next;
    if (newNode == NULL)
    {
	pthread_mutex_unlock(&q->headLock);
	return -1;
    }
    *value = tmp->val;
    q->head = newNode;
    pthread_mutex_unlock(&q->headLock);
    free(tmp);
    return 0;
}

void queue_display(queue* q)
{
    printf("queue:");
    printf("head=>");
    node* tmp = q->head;
    while (tmp)
    {
	printf("%d=>", tmp->val);
	tmp = tmp->next;
    }
    printf("end");
}

int main()
{
    queue que;
    int value;
    queue_init(&que);
    for (int i = 0; i < 10; ++i)
    {
	queue_enqueue(&que, i);
    }
    queue_dequeue(&que, &value);
    queue_display(&que);
    return 0;
}