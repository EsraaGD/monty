#include "monty.h"

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
}
