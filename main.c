#include "monty.h"
/**
 * main - Monty interpreter main function
 * @argc: Argument count
 * @argv: Argument values
 * Return: 0 on success, 1 on failure
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
	if ((file = fopen(argv[1], "r")) == NULL)
		error_file_open(argv[1]);
	instruction_t opcodes[] = {
		{"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", nop},
		{NULL, NULL}
	};
	while (getline(&line, &len, file) != -1) {
		line_number++;
		if ((opcode = strtok(line, " \t$\n")) == NULL || opcode[0] == '#') 
			continue;
	if ((flag = !strcmp(opcode, "push")))
	{
			value = strtok(NULL, " $\n");
			if (!value) print_push_error(line_number, file, line);
			for (i = 0; value[i]; i++)
				if (!isdigit(value[i]) && value[i] != '-')
					print_push_error(line_number, file, line);
			push(&stack, atoi(value));
		}
	if (!flag)
	{
			for (j = 0; opcodes[j].opcode; j++)
				if (!strcmp(opcode, opcodes[j].opcode))
				{
					opcodes[j].f(&stack, line_number);
					break;
				}
			if (j == 6) invalid_inst(line_number, opcode, file, line, stack);
		}
		free(line);
		line = NULL;
	}
	free_dlistint(stack);
	fclose(file);
	return (0);
}
