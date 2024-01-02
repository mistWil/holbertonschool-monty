#include "monty.h"


/**
 * push - Implements the push opcode
 * @stack: The stack
 * @line_number: Line number in the file
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, DELIMITERS);

	if (!arg || !is_valid_int(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Convertir l'argument en entier */
	int value = atoi(arg);

	/* Créer un nouveau nœud */
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Initialiser les valeurs du nouveau nœud */
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	/* Mettre à jour les liens du nœud précédent s'il existe */
	if (*stack)
		(*stack)->prev = new_node;

	/* Mettre à jour le pointeur de stack pour pointer vers le nouveau nœud */
	*stack = new_node;
}
