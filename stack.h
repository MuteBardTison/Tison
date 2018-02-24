/*
 * Stack_m.h --
 */
#ifndef _Stack_m_H
#define _Stack_m_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _stack {
    void *data;
    int top;
    int elemSize;
}Stack_m;
/**
 * \brief Create a new empty Stack_m.
 *
 * \return A handle for the new Stack_m.
 */
//Stack_m* Stack_m_new();
/**
 * \brief Push data (allocated by the caller) on the Stack_m.
 *
 * \param s The Stack_m to push data on.
 * \param data The pointer to data to be pushed on the Stack_m.
 */
//void Stack_m_push(Stack_m *s, void *data);
/**
 * \brief Pop data from the top of the Stack_m.
 *
 * \param s The Stack_m to pop data from.
 * \return The data or NULL if the Stack_m is empty.
 */
//void* Stack_m_pop(Stack_m *s);
/**
 * \brief Peek on the data at the top of the Stack_m.
 *
 * \param s The Stack_m to peek on.
 * \return The data or NULL if the Stack_m is empty.
 */
//void* Stack_m_peek(Stack_m *s);
/**
 * \brief Test whether a Stack_m is empty.
 *
 * \param s The Stack_m to test.
 * \return A non-zero value if the Stack_m is empty, 0 otherwise.
 */
//int Stack_m_empty(Stack_m *s);
/**
 * \brief Delete a Stack_m.
 *
 * \param s The Stack_m to delete.
 */
//void Stack_m_del(Stack_m *s);
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
#endif