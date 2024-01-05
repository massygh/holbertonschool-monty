#include "monty.h"
/**
 * dlistint_len - function that returns the number of elements in a linked list
 * @stack: pointer to the counter nodes
 * Return: the numbers of nodes
 */
size_t dlistint_len(const stack_t *stack)
{
	size_t i = 0;
	const stack_t *actual = stack;

	while (actual != NULL)
	{
		actual = actual->next;
		i++;
	}
	return (i);
}
