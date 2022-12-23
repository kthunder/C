#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define BUCKETS (101)

/*list func begain*/
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
/*list func end*/

typedef struct hash
{
    list lists[BUCKETS];
} hash;

void hash_init(hash* H)
{
    for (size_t i = 0; i < BUCKETS; i++)
    {
        list_init(&H->lists[i]);
    }
}

int hash_insert(hash* H, int val)
{
    int bucket = val % BUCKETS;
    return list_insert(&H->lists[bucket], val);
}

int hash_lookup(hash* H, int val)
{
    int bucket = val % BUCKETS;
    return list_lookup(&H->lists[bucket], val);
}

int main(int argc, char const* argv[])
{
    return 0;
}
