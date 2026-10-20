#include "stack.h"

stack new_stack() {
    stack s;

    s.top = -1;

    return s;
}

int push(stack* stack, long value) {
    if (stack->top == DEFAULT_STACK_SIZE - 1) {
        return 0;
    }
    stack->values[++stack->top] = value;
    return 1;
}

long peek(stack* stack) {
    if (stack->top == -1)
        return -1;

    long v = stack->values[stack->top];

    return v;
}

long pop(stack* stack) {
    if (stack->top == -1)
        return -1;

    long v = stack->values[stack->top];
    stack->top--;

    return v;
}