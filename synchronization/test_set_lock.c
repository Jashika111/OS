#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int lock=0;  //initalize lock variable to 0
 
void *thread_function(void *arg)
{
    //entry section
    while (__sync_lock_test_and_set(&lock,1)==1)
    {
        printf("Thread %d os waiting for the lock\n", *(int *)arg);
        }

        printf("THread %d has acquired the lock\n", *(int *)arg);

        //critical section
        printf("Thread %d is in the critical section\n", *(int *)arg);
    // Perform some task that requires exclusive access to a shared resource

    // Exit section
    lock = 0; // Release the lock
    printf("Thread %d has released the lock\n", *(int *)arg);

    return NULL;
}

int main(){
    pthread_t threads[5];
    int thread_args[5];
    //create  threads
    for(int i=0; i<5; i++){
        thread_args[i]=i;
        pthread_create(&threads[i], NULL, thread_function, &thread_args[i]);        
    }
    //wait for all threads to complete
    for (int i=0; i<5; i++)
    {
        pthread_join(threads[i], NULL);

    }
    return EXIT_SUCCESS;
}