#include "monty.h"
/**
 * sum_dlistint - function that adds the top two elements of the stack
 * @stack : pointer to list
 * Return: sum of top two elements or the stack
 */
int sum_dlistint(stack_t *stack)

{
	int sum = 0, i = 0;

	stack_t *current = stack;

	while (i < 2)
	{
		sum += current->n;
		current = current->next;
		i++;
	}
	return (sum);
}
