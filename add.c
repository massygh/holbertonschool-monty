#include "monty.h"

/**
 * add - Function that adds the top two elements of the stack.
 * @stack: stack struct
 * @line_number: line_number
 * Return: no return
 */
void add(stack_t **stack, unsigned int line_number)
{
    int sum;      // Variable pour stocker la somme des deux premiers éléments
    size_t nodes;  // Variable pour stocker le nombre de nœuds dans la liste

    // Utilisation de la fonction dlistint_len pour obtenir le nombre de nœuds
    nodes = dlistint_len(*stack);

    // Vérification si la pile contient au moins deux éléments
    if (nodes < 2)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    // Utilisation d'une fonction hypothétique sum_dlistint pour obtenir la somme des deux premiers éléments
    sum = sum_dlistint(*stack);

    // Suppression du deuxième élément de la pile
    pop(stack, line_number);

    // Modification du premier élément de la pile avec la somme obtenue
    (*stack)->n = sum;
}
