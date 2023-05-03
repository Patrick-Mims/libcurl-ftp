#include <curl/curl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#include "lc.h"

int main(void)
{
    // create a new thread object
    pthread_t thread1;

    int rc;
    void *result = NULL;

    // create new singlyList 

    struct Node *head = newSinglyLinkedList();

    // create new stack
    stack_t stack = newStack(10);

    push(stack, 100);
    push(stack, 200);
    push(stack, 300);
    push(stack, 400);
    push(stack, 500);

    peek();

    // create a new thread and pass the stack to it.
    // rc = pthread_create(&thread1, NULL, threadFtp, (void *)stack);

    rc = pthread_create(&thread1, NULL, *threadFtp, (void *)stack);

    if(rc == 0)
    {
        printf("Error: pthread_create() thread1\n");
        exit(EXIT_FAILURE);
    }

    rc = pthread_join(thread1, &result);

    // Detach the thread.
    if((pthread_detach(thread1)) > 0)
    {
        printf("Thread detached\n");
    }

    printf("[pthread_create] %d\n", rc);
    printf("[pthread_self] %u\n", pthread_self());
    //printf("[pthread_join] %d\n", (struct Node *)result);
    //pthread_exit((struct Node *)result);

    return 0;
}
