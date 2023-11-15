#include "monty.h"

/**
 * add - add top 2 elements of stack
 * @stack: ptr to top of stack
 * @line_number: ln of op
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next->next;
	free(temp);
}
