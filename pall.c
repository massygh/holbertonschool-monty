#include "monty.h"

/**
 * pall - Affiche toutes les valeurs de la pile.
 * @stack: Pointeur vers la pile
 * @line_number: Numéro de ligne dans le script
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    (void)line_number; // Paramètre non utilisé

    // Affiche chaque valeur dans la pile
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
