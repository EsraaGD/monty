#include "monty.h"

/**
 * pint - print val at top of stack
 * @stack: ptr to top of stack
 * @line_number: ln of opcode
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
