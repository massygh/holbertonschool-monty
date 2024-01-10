#include "monty.h"

/**
 * pint - Affiche la valeur du nœud supérieur de la pile.
 * @stack: Pointeur vers la pile
 * @line_number: Numéro de ligne dans le script
 */
void pint(stack_t **stack, unsigned int line_number)
{
    // Vérifie si la pile est vide
    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    // Affiche la valeur du nœud supérieur
    printf("%d\n", (*stack)->n);
}
