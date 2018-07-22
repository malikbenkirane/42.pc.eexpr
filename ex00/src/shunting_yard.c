/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shunting_yard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-kir <mben-kir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 22:55:10 by mben-kir          #+#    #+#             */
/*   Updated: 2018/07/22 23:02:59 by mben-kir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		else if (ISOPERATOR(token->token->data.operator))
		{
			parse_operator(token->token, operators, rpn);
		}
		token = token->next;
	}
	tok = stack_pop(operators);
	while (tok)
	{
		stack_push(tok, rpn);
		tok = stack_pop(operators);
	}
}

void	parse_operator(t_token *operator, t_stack **operators, t_stack **rpn)
{
	t_token		*tok;

	if (operator->data.operator == '(')
		stack_push(operator, operators);
	else if (operator->data.operator == ')')
	{
		tok = stack_pop(operators);
		while (tok->data.operator != '(')
			stack_push(tok, rpn);
		stack_pop(rpn);
	}
	else if ((*operators)->top &&
				((*operators)->top->data.operator != '(' &&
				(*operators)->top->data.operator != ')') &&
			cmp_precedence(
				(*operators)->top->data.operator,
				operator->data.operator) <= 0)
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
