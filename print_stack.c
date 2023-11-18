#include "monty.h"

/**
 * print_stack - Print the elements of the stack
 * @stack: Pointer to the top of the stack
 */
void print_stack(stack_t *stack)
{
	printf("Stack elements:");

	while (stack != NULL)
	{
		printf(" %d", stack->n);
		stack = stack->next;
	}

	printf("\n");
}
