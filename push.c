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
	stack_t *new_node;

	while (*input && (*input == ' ' || *input == '\t'))
		input++;

	printf("Input: '%s'\n", input);

	if (*input == '\0' || strncmp(input, "push", 4) != 0 || sscanf(input,"push  %d", &num) != 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = atoi(input);

	printf("Pushing %d to stack\n", num);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;

	printf("Stack after push:\n");
	print_stack(*stack);
}
