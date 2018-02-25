#include <stdio.h>
#include "stack.h"

int main() {
    Stack_m* ptr = stack_new();
    printf("%d\n", stack_empty(ptr));
    stack_push(ptr, "A");
    printf("%d\n", stack_empty(ptr));
    stack_push(ptr, "B");
    stack_push(ptr, "C");
    stack_push(ptr, "D");
    stack_push(ptr, "E");
    stack_push(ptr, "F");
    stack_push(ptr, "G");
    stack_push(ptr, "H");
	
	for (int i = 0; i < 8; i++){
		char* s = (char*)malloc(sizeof(char));
		s = stack_peek(ptr);
		printf("peep%s\n", s);
		char* v = (char*)malloc(sizeof(char));
		v = stack_pop(ptr);
		printf("pop%s\n", v);
		free(v);
		free(s);
	}
	stack_del(ptr);
}
