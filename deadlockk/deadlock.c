#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t first_mutex;
pthread_mutex_t second_mutex;

void *function1(void *arg);
void *function2(void *arg);

int main()
{
    pthread_t one, two;

    pthread_mutex_init(&first_mutex, NULL);
    pthread_mutex_init(&second_mutex, NULL);

    pthread_create(&one, NULL, function1, NULL);
    pthread_create(&two, NULL, function2, NULL);

    pthread_join(one, NULL);
    pthread_join(two, NULL);

    pthread_mutex_destroy(&first_mutex);
    pthread_mutex_destroy(&second_mutex);

    printf("Threads joined\n");
    return 0;
}

void *function1(void *arg)
{
    pthread_mutex_lock(&first_mutex);
    printf("Thread ONE acquired first_mutex\n");

    sleep(1);

    pthread_mutex_lock(&second_mutex);
    printf("Thread ONE acquired second_mutex\n");

    pthread_mutex_unlock(&second_mutex);
    pthread_mutex_unlock(&first_mutex);

    return NULL;
}

void *function2(void *arg)
{
    pthread_mutex_lock(&second_mutex);
    printf("Thread TWO acquired second_mutex\n");

    sleep(1);

    pthread_mutex_lock(&first_mutex);
    printf("Thread TWO acquired first_mutex\n");

    pthread_mutex_unlock(&first_mutex);
    pthread_mutex_unlock(&second_mutex);

    return NULL;
}
// 12