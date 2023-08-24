#include "monty.h"
/**
* pall - Prints stack values from top to bottom
* @head_ptr: ptr to top of the stack
* @current_line_number: current line number in the Monty bytecode file
* Return - void
*/
void pall(stack_t **head_ptr, unsigned int current_line_number)
{
	stack_t *h = NULL;
	(void)current_line_number;

	h = *head_ptr;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}