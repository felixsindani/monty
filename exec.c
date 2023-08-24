#include "monty.h"
/**
 * exec - executes an opcode on a ptr_top_stack
 * @line: The line containing the opcode to exec.
 * @line_number_of_opcode: The line number of the opcode in the input file.
 * @ptr_top_stack: A pointer to the top of the ptr_top_stack.
 * Return: 0 if the opcode is a comment or if the line is empty, 1 otherwise.
 */
int exec(char *line, unsigned int line_number_of_opcode, stack_t **ptr_top_stack)
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int i = 0;
	int opcode_found = 0;
	char *opcode;

	opcode = strtok(line, " \t\n");
	if (!opcode || *opcode == '#' || opcode[0] == '#')
	{
		return (0);
	}
	col.arg = strtok(NULL, " \t\n");
	while (opcodes[i].opcode != NULL && opcode != NULL)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(ptr_top_stack, line_number_of_opcode);
			opcode_found = 1;
			break;
		}
		i++;
	}
	if (opcode_found == 0)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number_of_opcode, opcode);
		exit(EXIT_FAILURE);
	}
	return (1);
}
