#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

pthread_t mythread1, mythread2;
pthread_mutex_t mymutex;

void *anotherFunc(void *arg)
{
    pthread_mutex_lock(&mymutex);
    int i;

    for(i = 0; i < 100; i++)
        printf("anotherFunc\n");

    pthread_mutex_unlock(&mymutex);

    pthread_exit(NULL);
}

void *func(void *arg)
{
    pthread_mutex_lock(&mymutex);
    int i;
    for(i = 0; i < 100; i++)
        printf("func\n");

    pthread_mutex_unlock(&mymutex);

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_mutex_init(&mymutex, NULL);

    pthread_create(&mythread1, NULL, func, NULL);
    pthread_create(&mythread2, NULL, anotherFunc, NULL);


    pthread_join(mythread1, NULL);
    pthread_join(mythread2, NULL);

    pthread_mutex_destroy(&mymutex);

   return EXIT_SUCCESS;
}
