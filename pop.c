#include "monty.h"

/**
 * pop - Supprime le nœud supérieur de la pile.
 * @stack: Pointeur vers la pile
 * @line_number: Numéro de ligne dans le script
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *node_to_delete;
    (void)line_number; // Paramètre non utilisé

    // Vérifie si la pile est vide
    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    // Supprime le nœud supérieur et met à jour les liens
    node_to_delete = *stack;
    *stack = node_to_delete->next;
    if (node_to_delete->next)
        node_to_delete->next->prev = NULL;
    free(node_to_delete);
}
