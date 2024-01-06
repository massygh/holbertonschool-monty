#include "monty.h"
/**
 * main - Entry point of the stack-based interpreter program.
 * @argc: Argument count.
 * @argv: Argument vector, argv[1] is expected to be the file to interpret.
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on error.
 */
int main(int argc, char *argv[])
{
	char *opcode, *value, *line = NULL;
	size_t line_number = 0, len = 0;
	FILE *file;
	int i, j, flag;
	stack_t *stack = NULL;

	if (argc != 2)
		error_usage();

	file = fopen(argv[1], "r");
	if (file == NULL)
		error_file_open(argv[1]);

	instruction_t opcodes[] = {
		{"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", nop}, {NULL, NULL},
	};
	while (getline(&line, &len, file) != -1)
	{
		flag = 0;
		line_number++;
		opcode = strtok(line, " \t$\n");
		if (opcode == NULL || opcode[0] == '#')
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			value = strtok(NULL, " $\n");
			if (value == NULL)
				print_push_error(line_number, file, line);

			for (i = 0; value[i] != '\0'; i++)
			{
				if  (!isdigit(value[i]) && value[i] != '-')
					print_push_error(line_number, file, line);
			}
			push(&stack, atoi(value));
			flag = 1;
		}
		if (flag == 0)
		{
			for (j = 0; opcodes[j].opcode != NULL; j++)
			{
				if (strcmp(opcode, opcodes[j].opcode) == 0)
				{
					opcodes[j].f(&stack, line_number);
					break;
				}
			}
		}
		if (j == 6)
			invalid_inst(line_number, opcode, file, line, stack);
		free(line);
		line = NULL;
	}
	free_dlistint(stack);
	free(line);
	fclose(file);
	return (0);
}
