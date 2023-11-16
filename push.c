#include "monty.h"

/**
 * push - push something to stack
 * @stack:ptr to top of stack
 * @line_number: ln of op
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *input = data.input;
	int num = atoi(input);
	stack_t *new_node;

	if (num == 0 && strcmp(input, "0") != 0)
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->next = *stack;
	*stack = new_node;
}
