#include "monty.h"

/**
 * main - entry point
 * @argc: # of command line arguments
 * @argv: arr of cla strings
 * Return: 0 for success, error message on failure
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	data_t.input = argv[1];
	data_t.file = fopen(data_t.input, "r");

	if (data_t.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", data_t.input);
		exit(EXIT_FAILURE);
	}
	fclose(data_t.file);
	exec_file(argv[1], &stack, line_number);
	free_me(&stack);
	return (0);
}
