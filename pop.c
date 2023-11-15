#include "monty.h"

/**
 * pop - removes top element of stack
 * @stack: ptr to top of stack
 * @line_number: ln of op
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);

	if (*stack != NULL)
		(*stack)->prev = NULL;
}
