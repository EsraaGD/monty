#include "monty.h"

/**
 * push - push something to stack
 * @stack:ptr to top of stack
 * @line_number: ln of op
 */

void push(stack_t **stack, unsigned int line_number)
{
	const char *input = data.input;
	int num = 0;

	while (*input && (*input == ' ' || *input == '\t'))
		input++;

	if (*input == '\0' || strncmp(input, "push", 4) != 0 || sscanf(input, "push  %d", &num) != 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = atoi(data.input + 4);

	add_node(stack, num);
}
