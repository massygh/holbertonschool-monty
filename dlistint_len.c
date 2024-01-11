#include "monty.h"

/**
 * dlistint_len - function that returns the number of elements in a linked list
 * @stack: pointer to the counter nodes
 * Return: the numbers of nodes
 */
size_t dlistint_len(const stack_t *stack)
{
    size_t i = 0;  // Variable pour stocker le nombre de nœuds
    const stack_t *actual = stack;  // Pointeur temporaire pour parcourir la liste

    while (actual != NULL)
    {
        actual = actual->next;  // Déplacement vers le nœud suivant
        i++;  // Incrémentation du compteur de nœuds
    }

    return (i);  // Retourne le nombre total de nœuds dans la liste
}
