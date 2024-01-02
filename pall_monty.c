#include "monty.h"

/**
 * pall - Implements the pall opcode
 * @stack: The stack
 * @line_number: Line number in the file
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}

	/*Évite un avertissement pour une variable non utilisée*/
	(void)line_number;
}
