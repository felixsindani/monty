#include "monty.h"
col_t col = {NULL, NULL, NULL};
/**
* main - Entry point of Monty interpreter
* @argc: Number of command-line arguments
* @argv: Array of command-line arguments
* Return: 0 on success, otherwise EXIT_FAILURE on failure
*/
int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
    stack_t *stac = NULL;
	FILE *file;
	ssize_t nread;
	unsigned int current_line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	col.file = file;
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((nread = getline(&line, &len, file)) != -1)
	{
		current_line_number++;
		if (exec(line, current_line_number, &stac) == 0)
			continue;
	}
	free_all_stack(&stac);
	free(line);
	fclose(file);
	exit(EXIT_SUCCESS);
	return (0);
}