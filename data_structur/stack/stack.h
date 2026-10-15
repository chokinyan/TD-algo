#ifndef MY_STACK
#define MY_STACK

#define DEFAULT_STACK_SIZE 1000

typedef struct stack {
    long values[DEFAULT_STACK_SIZE];
    int top;
} stack;

stack new_stack();

int push(stack* stack, long value);

long peek(stack* stack);
long pop(stack* stack);

#endif /* MY_STACK */
