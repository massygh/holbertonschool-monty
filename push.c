#include "monty.h"

/**
 * push - Ajoute un élément au sommet de la pile.
 * @stack: Pointeur vers la pile
 * @value: Valeur à ajouter à la pile
 */
void push(stack_t **stack, int value)
{
    stack_t *new_node;

    // Alloue de la mémoire pour le nouveau nœud
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialise le nouveau nœud avec la valeur donnée
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    // Met à jour les liens de la pile
    if (*stack != NULL)
        (*stack)->prev = new_node;
    *stack = new_node;
}
