#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	/* Check if the next token is available */
	if (!tokens || !tokens[1])
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Convert the next token to an integer */
	int value = atoi(tokens[1]);

	/* Create a new node for the stack */
	stack_t *new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}
