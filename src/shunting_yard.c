#include "tokens.h"
#include "stack.h"
#include "yard.h"

void	ft_syard(t_tokens_list *tokens, t_stack **operators, t_stack **rpn)
{
	t_tokens	*token;
	t_token		*tok;

	token = tokens->head;
	while (token)
	{
		if (token->token->as_number)
		{
			stack_push(token->token, rpn);
		}
		else if (ISOPERATOR(token->token->operator))
		{
			parse_operator(token->token, operators, rpn);
		}
		else
		{
			tok = stack_pop(operators);
			stack_push(tok, rpn);
		}
		token = token->next;
	}
}

void	parse_operator(t_token *operator, t_stack **operators, t_stack **rpn)
{
	t_token		*tok;

	if (operator->operator == '(')
		stack_push(operator, operators);
	else if (operator->operator == ')')
	{
		tok = stack_pop(operators);
		while(tok->operator != '(')
			stack_push(tok, rpn);
		stack_pop(rpn);
	}
	else if ((*operators)->top &&
			cmp_precedence((*operators)->top->operator, operator->operator) <= 0)
	{
		tok = stack_pop(operators);
		stack_push(tok, rpn);
	}
	else
		stack_push(operator, operators);
}

int		op_index(char op)
{
	if (op == '+')
		return (PLUS);
	if (op == '-')
		return (MINUS);
	if (op == '*')
		return (TIMES);
	if (op == '/')
		return (DIV);
	if (op == '%')
		return (MOD);
	return (-1);
}

int		cmp_precedence(char op1, char op2)
{
	return (PRECEDENCE[op_index(op1)] - PRECEDENCE[op_index(op2)]);
}
