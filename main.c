#include "monty.h"
/**
 * main - Entry point of the stack-based interpreter program.
 * @argc: Argument count.
 * @argv: Argument vector, argv[1] is expected to be the file to interpret.
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on error.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	char *opcode;
	instruction_t instructions[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", nop}, {NULL, NULL}
	};
	int i;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		error_usage();
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		error_file_open(argv[1]);
		return (EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		if (opcode == NULL || opcode[0] == '#')
			continue;
		for (i = 0; instructions[i].opcode; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, line_number);
				break;
			}
		}
		if (instructions[i].opcode == NULL)
			invalid_inst(line_number, opcode, file, line, stack);
	}
	free(line);
	fclose(file);
	free_dlistint(stack);
	return (EXIT_SUCCESS);
}
