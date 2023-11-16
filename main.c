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
	data_t data;

	data.val = NULL;
	data.input = argv[1];
	data.file = fopen(data.input, "r");

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (data.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", data.input);
		exit(EXIT_FAILURE);
	}

	exec_file(&stack);
	free_me(&stack);
	fclose(data.file);
	exit(EXIT_SUCCESS);
}
