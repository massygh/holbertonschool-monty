#include "monty.h"

/**
 * swap - Échange les valeurs de deux nœuds adjacents dans la pile.
 * @stack: Pointeur vers la pile
 * @line_number: Numéro de ligne dans le script
 */
void swap(stack_t **stack, unsigned int line_number)
{
    int temp2;
    size_t nodes;
    stack_t *node_to_swap = *stack;
    (void)line_number; // Paramètre non utilisé

    // Vérifie si la pile a au moins deux éléments
    nodes = dlistint_len(*stack);
    if (nodes < 2)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    // Échange les valeurs des deux premiers nœuds
    node_to_swap = *stack;
    temp2 = node_to_swap->n;
    node_to_swap->n = node_to_swap->next->n;
    node_to_swap->next->n = temp2;
}
