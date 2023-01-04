#include <stdio.h>
#include <assert.h>
#include <pthread.h>

static volatile int counter = 0;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* myThread(void* arg)
{
	for (size_t i = 0; i < 1000000; i++)
	{
		counter++;
	}
	printf("%s : %d\n", (char*)arg, counter);

	return NULL;
}

void* myLockedThread(void* arg)
{
	for (size_t i = 0; i < 1000000; i++)
	{
		pthread_mutex_lock(&lock);
		counter++;
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}

int main(int argc, char const* argv[])
{
	pthread_t thread1;
	pthread_t thread2;

	pthread_create(&thread1, NULL, myLockedThread, "A");
	pthread_create(&thread2, NULL, myLockedThread, "B");

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	return 0;
}
