#ifndef LC_H
#define LC_H

// Incomplete Type's
typedef struct Stack *stack_t;
typedef struct Curl *curl_t;

struct listNode {
    int *data;
    struct listNode *next;
};

struct queueNode {
    int *data;
    struct queueNode *next;
};

stack_t newStack(int);

/* stack */
int isFull(stack_t);
void push(stack_t, int);

/* threads */
static void *threadFtp(void *);

#endif
