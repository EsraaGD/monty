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

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (FILE == NULL,not able to open file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if (can't malloc)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}
