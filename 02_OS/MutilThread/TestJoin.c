#include <pthread.h>
#include <stdio.h>

void* child(void* args)
{
    printf("this is child\n");
    return NULL;
}

int main(int argc, char const* argv[])
{
    printf("parent begin\n");
    pthread_t thread;
    pthread_create(&thread, NULL, child, NULL);
    pthread_join(thread, NULL);
    printf("parent end\n");
    return 0;
}
