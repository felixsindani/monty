#include "monty.h"
/**
* pint - prints value at top_of_stack of the stack then new line
* @top_of_stack: double pointer to top of stack
* @current_line_number: current line number of the opcode
* Return: void
*/
void pint(stack_t **top_of_stack, unsigned int current_line_number)
{

	if (*top_of_stack == NULL)
	{
		fprintf(stderr, "L%u: Cannot pint, stack empty\n", current_line_number);
		fclose(col.file);
		free(col.line);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*top_of_stack)->n);
	}

}