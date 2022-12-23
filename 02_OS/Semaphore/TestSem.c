#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t s;

int main(int argc, char const *argv[])
{
    sem_init(&s, 0, 1);

    return 0;
}
