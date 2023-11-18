#include "monty.h"

/**
 * exec_op - function to execute opcode
 * @opcode: op to be executed
 * @stack: ptr to top of stack
 * @line_number: ln of opcode
 */

void exec_op(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int q = 0;

	while (instruction[q].opcode != NULL)
	{
		if (strcmp(opcode, instruction[q].opcode) == 0)
		{
			instruction[q].f(stack, line_number);
			return;
		}
		q++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

/**
 * exec_file - Process the lines
 * @stack: ptr to ptr to top of stack
 * Return: void
 */

void exec_file(stack_t **stack);
void exec_file(stack_t **stack)
{
	size_t len = 0;
	ssize_t nread;
	unsigned int line_number = 0;

	if (data.file == NULL)
	{
		fprintf(stderr, "Error: File pointer is NULL\n");
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&data.input, &len, data.file)) != -1)
	{
		char *input_copy = strdup(data.input);
		char *temp;
		char *opcode;

		if (input_copy == NULL)
		{
			fprintf(stderr, "Error: Memory allocation error\n");
			exit(EXIT_FAILURE);
		}

		temp = input_copy;
		opcode = strtok(temp, " \t\n");

		if (opcode == NULL || *opcode == '#')
		{
			free(input_copy);
			continue;
		}

		data.val = strtok(NULL, " \t\n");

		exec_op(opcode, stack, line_number);

		free(input_copy);
	}

	free(data.input);
}
