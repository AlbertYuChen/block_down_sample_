// thread1.c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *thread_fnc(void * arg);

char thread_msg[] ="Hello Thread!";  // global

int main()
{
        int ret;
        pthread_t my_thread;
        void *ret_join;

        ret =  pthread_create(&my_thread, NULL, thread_fnc, (void*) thread_msg);

        printf("Waiting for thread to finish...\n");
        ret = pthread_join(my_thread, &ret_join);

        printf("Thread joined, it returned %d\n", ret_join);

        printf("New thread message: %s\n",(char *)thread_msg);
        exit(EXIT_SUCCESS);
}

void *thread_fnc(void *arg)
{
        printf("This is thread_fnc(), arg is %s\n", (char *) arg);
        strcpy(thread_msg,"Bye!");
        int return_message = 111;
        pthread_exit((void *)return_message);
}