#include "monty.h"

/**
 * add_node - add a new node to the stack
 * @stack: pointer to the top of the stack
 * @num: value to be added to the new node
 * Return: void
 */
stack_t *add_node(stack_t **stack, const int num)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		free_me(stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->prev = NULL;

	if (*stack == NULL)
		new_node->next = NULL;
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	*stack = new_node;

	return (new_node);
}
