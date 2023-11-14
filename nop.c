#include "monty.h"

/**
 * nop - This opcode does not do anything.
 * @stack: ptr to to top of stack
 * @line_number: current LN of hte opcode in monty file
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
