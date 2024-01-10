#include "monty.h"

/**
 * sum_dlistint - Calcule la somme des deux éléments supérieurs de la pile.
 * @stack: Pointeur vers la pile
 * Return: Somme des deux éléments supérieurs de la pile
 */
int sum_dlistint(stack_t *stack)
{
    int sum = 0;
    int i = 0;
    stack_t *current = stack;

    // Ajoute les valeurs des deux éléments supérieurs de la pile
    while (i < 2)
    {
        sum += current->n;
        current = current->next;
        i++;
    }
    return sum;
}
