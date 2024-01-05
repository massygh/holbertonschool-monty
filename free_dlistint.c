#include "monty.h"
/**
 * free_dlistint - function that frees a list
 * @stack: pointer to free tmp
 * Return: void
 */
void free_dlistint(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
