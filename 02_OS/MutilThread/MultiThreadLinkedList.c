#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node* next;
} node;

typedef struct list
{
    struct node* head;
    pthread_mutex_t lock;
} list;

void list_init(list* L)
{
    L->head = NULL;
    pthread_mutex_init(&L->lock, NULL);
}

int list_insert(list* L, int val)
{
    node* new = malloc(sizeof(node));
    if (new == NULL)
    {
        perror("malloc");
        return 1;
    }
    new->val = val;

    pthread_mutex_lock(&L->lock);
    new->next = L->head;
    L->head = new;
    pthread_mutex_unlock(&L->lock);
}

int list_lookup(list* L, int val)
{
    int res = -1;
    pthread_mutex_lock(&L->lock);
    node* curr = L->head;
    while (curr)
    {
        if (curr->val == val)
        {
            res = 0;
            break;
        }
        curr = curr->next;
    }
    pthread_mutex_unlock(&L->lock);
    return res;
}

void list_display(list* L)
{
    printf("list:");
    printf("head=>");
    node* tmp = L->head;
    while (tmp)
    {
        printf("%d=>", tmp->val);
        tmp = tmp->next;
    }
    printf("end");
}

int main(int argc, char const* argv[])
{
    list L;
    list_init(&L);
    for (size_t i = 0; i < 10; i++)
    {
        list_insert(&L, i);
    }
    list_display(&L);

    return 0;
}
