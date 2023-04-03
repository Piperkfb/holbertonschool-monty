#include "monty_head.h"
/**
 * monty_pint - prints top valul of stack
 * @stack: pointer to top node
 * @line_number: working line number
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pint_error(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}
/**
 * monty_swap - Swaps two stack positions
 * @stack: pointer to top node
 * @line_number - wokring line number
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "swap"));
		return;
	}

	temp = (*stack)->next->next;
	(*stack)->next->next = temp->next;
	(*stack)->next->prev = temp;
	if (temp->next)
		temp->next->prev = (*stack)->next;
	temp->next = (*stack)->next;
	temp->prev = *stack;
	(*stack)->next = temp;
}
/**
 * monty_nop - Does nothing at all as a opcode
 * @stack: pointer to top node of stack
 * @line_number: Line position that is being worked on in stack
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
