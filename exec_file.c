#include "monty.h"

/**
 * exec_file - Process the lines
 * @opcode: ptr to string representing opcode
 * @stack: ptr to ptr to top of stack
 * @line_number: line number in file
 */

void exec_file(char *opcode, stack_t **stack, unsigned int line_number)
{
	int isthere = 0;
	int q = 0;

	strtok(NULL, " \n\t");

	if (opcode == NULL || *opcode == '#')
		return;

	while (instruction[q].opcode != NULL)
	{
		if (strcmp(opcode, instruction[q].opcode) == 0)
		{
			isthere = 1;
			instruction[q].f(stack, line_number);
			return;
		}
		q++;
	}

		if (!isthere)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
}
