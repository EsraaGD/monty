#include "monty.h"
/**
 * free_me - free stack_t
 * @stack: ptr to top of stack
 */

void free_me(stack_t **stack)
{
	stack_t *current, *ne_node;

	for (current = *stack; current != NULL; current = ne_node)
	{
		ne_node = current->next;
		free(current);
	}

	*stack = NULL;
}
