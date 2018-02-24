#include <stdio.h>
#include "stack.h"

int main() {
    Stack_m* ptr = stack_new();
    printf("%d", stack_empty(ptr));
    stack_push(ptr, "Q");
    printf("%d", stack_empty(ptr));
    stack_push(ptr, "S");
    stack_push(ptr, "E");
    stack_push(ptr, "A");
    stack_push(ptr, "B");
    stack_push(ptr, "C");
    stack_push(ptr, "D");
    //printf("%d", stack_empty(ptr));
    for (int i = 0; i < 7; i++){
        printf("TOP: %s\n",stack_peek(ptr));
        printf("%s\n", stack_pop(ptr));
    }
    printf("%d", stack_empty(ptr));
    stack_del(ptr);
}