#include "monty.h"
/**
 * free_me - free stack_t
 * @stack: ptr to top of stack
 */

void free_me(stack_t **stack)
{
	stack_t *current;

	for (current = *stack; current != NULL;)
	{
		*stack = current->next;
		free(current);
		current = *stack;
	}
}
