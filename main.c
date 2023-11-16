#include "monty.h"

data_t data = {NULL, NULL, NULL};

/**
 * main - entry point
 * @argc: # of command line arguments
 * @argv: arr of cla strings
 * Return: 0 for success, error message on failure
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	exec_file(&stack);
	free_me(&stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}
