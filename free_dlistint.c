#include "monty.h"

/**
 * free_dlistint - function that frees a list
 * @stack: pointer to free tmp
 * Return: void
 */
void free_dlistint(stack_t *stack)
{
    stack_t *tmp;  // Déclaration d'un pointeur temporaire

    while (stack != NULL)
    {
        tmp = stack;      // Sauvegarde du nœud actuel dans tmp
        stack = stack->next;  // Déplacement vers le nœud suivant
        free(tmp);         // Libération de la mémoire allouée pour le nœud actuel
    }
}
