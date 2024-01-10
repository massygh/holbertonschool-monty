#include "monty.h"

/**
 * main - Point d'entrée du programme interpréteur basé sur la pile.
 * @argc: Nombre d'arguments.
 * @argv: Vecteur d'arguments, argv[1] est censé être le fichier à interpréter.
 * Return: EXIT_SUCCESS en cas de succès, EXIT_FAILURE en cas d'erreur.
 */
int main(int argc, char *argv[])
{
    char *opcode, *value, *line = NULL;
    size_t line_number = 0, len = 0;
    FILE *file;
    int i, j, flag;
    stack_t *stack = NULL;

    // Vérifie le nombre d'arguments
    if (argc != 2)
        error_usage();

    // Ouvre le fichier en mode lecture
    file = fopen(argv[1], "r");
    if (file == NULL)
        error_file_open(argv[1]);

    // Tableau des opcodes et de leurs fonctions associées
    instruction_t opcodes[] = {
        {"pall", pall}, {"pint", pint}, {"pop", pop},
        {"swap", swap}, {"add", add}, {"nop", nop}, {NULL, NULL},
    };

    // Lit chaque ligne du fichier
    while (getline(&line, &len, file) != -1)
    {
        flag = 0;
        line_number++;
        // Extrait l'opcode de la ligne
        opcode = strtok(line, " \t$\n");
        if (opcode == NULL || opcode[0] == '#')
            continue;

        // Vérifie si l'opcode est "push"
        if (strcmp(opcode, "push") == 0)
        {
            // Extrait la valeur associée à "push"
            value = strtok(NULL, " $\n");
            if (value == NULL)
                print_push_error(line_number, file, line);

            // Vérifie que la valeur est un entier
            for (i = 0; value[i] != '\0'; i++)
            {
                if (!isdigit(value[i]) && value[i] != '-')
                    print_push_error(line_number, file, line);
            }
            // Ajoute la valeur à la pile
            push(&stack, atoi(value));
            flag = 1;
        }

        // Vérifie si l'opcode correspond à une fonction prédéfinie
        if (flag == 0)
        {
            for (j = 0; opcodes[j].opcode != NULL; j++)
            {
                if (strcmp(opcode, opcodes[j].opcode) == 0)
                {
                    // Exécute la fonction associée à l'opcode
                    opcodes[j].f(&stack, line_number);
                    break;
                }
            }
        }

        // Gère le cas où l'opcode est inconnu
        if (j == 6)
            invalid_inst(line_number, opcode, file, line, stack);

        // Libère la mémoire de la ligne
        free(line);
        line = NULL;
    }

    // Libère la mémoire de la pile
    free_dlistint(stack);
    // Libère la mémoire de la ligne
    free(line);
    // Ferme le fichier
    fclose(file);
    return (EXIT_SUCCESS);
}
