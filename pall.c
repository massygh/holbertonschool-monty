#include "monty.h"

void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number; /* Unused parameter */

	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
