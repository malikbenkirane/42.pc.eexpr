/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-kir <mben-kir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 22:53:45 by mben-kir          #+#    #+#             */
/*   Updated: 2018/07/22 22:59:28 by mben-kir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stack.h"

t_stack	*stack_init(t_token *top)
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack)
		stack->top = top;
	return (stack);
}

t_token	*stack_pop(t_stack **stack)
{
	t_stack *tmp;
	t_token *top;

	if (!*stack)
		return (NULL);
	top = (*stack)->top;
	tmp = *stack;
	*stack = (*stack)->stack;
	free(tmp);
	return (top);
}

void	stack_push(t_token *token, t_stack **stack)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return ;
	new->top = token;
	if (*stack)
		new->stack = *stack;
	*stack = new;
}
