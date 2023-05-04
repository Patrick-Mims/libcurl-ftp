#include <curl/curl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#include "lc.h"

struct Node *newSinglyLinkedList() 
{
    struct Node *node = NULL;

    if((node = malloc(sizeof(struct Node))) == NULL)
    {
        printf("Error: newSinglyLinkedList()");
        exit(EXIT_FAILURE);
    }

    return node;
}
