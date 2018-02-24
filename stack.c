/*
 * stack.c --
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

Stack_m* stack_new() {
    Stack_m* s = (Stack_m*)malloc(sizeof(Stack_m));
    s->top = -1;
    s->data = malloc(sizeof(s->elemSize));
    return s;
}

void stack_push(Stack_m *s, void *data) {
    s->elemSize = sizeof(data);
    s->top++;
    void* target = (char*)s->data + s->top * s->elemSize;
    memcpy(target, data, s->elemSize);
    
}

void* stack_pop(Stack_m *s) {
    if(stack_empty(s))
        return NULL;
    else {
        void* data = malloc(s->elemSize);
        void* source = (char*)s->data + s->top * s->elemSize;
        memcpy(data, source, s->elemSize);
        s->top--;
        return data;
    }
}

void* stack_peek(Stack_m *s) {
    if(stack_empty(s))
        return NULL;
    else {
        void* target = malloc(s->elemSize);
        void* source = (char*)s->data + s->top * s->elemSize;
        memcpy(target, source, s->elemSize);
        return target;
    }
}

int stack_empty(Stack_m *s) {
    return s->top == -1;
}

void stack_del(Stack_m *s) {
    free(s->data);
    free(s);
}