#include "monty.h"

/**
 * pall - prints all vals in stack
 * @stack: ptr to top of stack
 * @line_number: current LN of opcode in monty
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	node = *stack;

	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}

	(void)line_number;

	if (*stack == NULL)
		return;
}

/*for (stack_t *current = *stack; current != NULL; current = current->next)*/
