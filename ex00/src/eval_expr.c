#include <stdlib.h>
#include "yard.h"
#include "tokens.h"
#include "eval_expr.h"

int	eval_expr(char *str)
{
	t_tokens_list	*tokens;
	t_stack			*operators;
	t_stack			*rpn;

	tokens = tokenize(str);

	if (!(operators = stack_init(NULL)) || !(rpn = stack_init(NULL)))
		return (0);

	ft_syard(tokens, &operators, &rpn);
	return compute_rpn(&rpn);
}


int compute_rpn(t_stack **rpn)
{
	int number1;
	int number2;
	t_stack *cstack;
	t_token	*tok;

	if (!(cstack = stack_init(NULL)))
		return (0);
	tok = stack_pop(rpn);
	while (tok)
	{
		if (tok->as_number)
			stack_push(tok, &cstack);
		else
		{
			number1 = stack_pop(&cstack)->data.number;
			number2 = stack_pop(&cstack)->data.number;
			compute_op(number1, number2, tok->data.operator, &cstack);
		}
		tok = stack_pop(rpn);
	}
	number1 = stack_pop(&cstack)->data.number;
	return (number1);
}


void compute_op(int number1, int number2, char operator, t_stack **cstack)
{
	if (operator == '+')
		stack_push(init_number_token(number1 + number2), cstack);
	if (operator == '-')
		stack_push(init_number_token(number1 - number2), cstack);
	if (operator == '*')
		stack_push(init_number_token(number1 * number2), cstack);
	if (operator == '/' && number2 != 0)
		stack_push(init_number_token(number1 / number2), cstack);
}
