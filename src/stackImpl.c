#include <curl/curl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#include "lc.h"

struct Stack 
{
    char *file;
    int *fileSize;
    int *data;
    int ptr;
    int size;
};

// method creates and returns a new node of type stack_t 
stack_t newStack(int size)
{
    stack_t stack; 

    // initialize the stack
    if((stack = malloc(sizeof(stack_t))) == NULL)
    {
        printf("Cannot Allocate Memory\n");
        exit(EXIT_FAILURE);
    }

    // initialize the array in the stack
    if((stack->data = malloc(size * sizeof(int))) == NULL)
    {
        printf("Cannot Allocate Memory\n");
        free(stack);
        exit(EXIT_FAILURE);
    }

    stack->size = size;
    stack->ptr = 0;

    return stack;
}

// if the ptr and stack are equal, the stack is full
int isFull(stack_t stack)
{
    return (stack->ptr == stack->size);
}

void push(stack_t stack, int item)
{
    if(isFull(stack)) 
        exit(EXIT_FAILURE);

    stack->data[stack->ptr] = item;
    stack->ptr++;
}

void peek(stack_t stack)
{
    int i;

    for(i = 0; i < stack->ptr; i++) 
    {
        printf("[stack] %d\n", stack->data[i]);
    }
}

/*
   int isEmpty()
   {

   }

   void pop()
   {

   }
 */
