// thread01.c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define N 20

void *worker_thread_1(void *arg)
{
    printf("This is worker_thread #%ld\n", (long)arg);
    pthread_exit(NULL);
}

void many_threads(){
    pthread_t my_thread[N];

    long id;
    for(id = 1; id <= N; id++) {
            int ret =  pthread_create(&my_thread[id], NULL, &worker_thread_1, (void*)id);
            if(ret != 0) {
                    printf("Error: pthread_create() failed\n");
                    exit(EXIT_FAILURE);
            }
    }

    // pthread_exit(NULL);

}


void *worker_thread_2(void *arg)
{
        pthread_exit((void*)((long)arg * 2));
}

void threads_join()
{
        int i;
        long input = 10;
        pthread_t thread;
        pthread_create(&thread, NULL, worker_thread_2, (void *)input);
        pthread_join(thread, (void **)&i);
        printf("%d\n",i);  // will print out 911

}

// int main()
// {
//     // many_threads();
//     threads_join();
// }
