/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-kir <mben-kir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 22:55:34 by mben-kir          #+#    #+#             */
/*   Updated: 2018/07/22 23:01:06 by mben-kir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tokens.h"
#include "tools.h"

/*
** TODO split tokenize.c -> tokenize.c, tokens_list.c
** TODO rename t_tokens_list -> t_tlist
** TODO fix memory leaks / add some free methods
*/

t_tokens_list	*tokenize(char *str)
{
	t_tokens_list	*tokens;
	int				number;

	tokens = (t_tokens_list *)malloc(sizeof(t_tokens_list));
	tokens->head = NULL;
	tokens->tail = NULL;
	while (*str)
	{
		while (ISSPACE(*str))
			str++;
		if (*str == '\0')
			break ;
		if ((number = ft_atoi_fwd(&str)))
			push_token(tokens, 1, NULL, &number);
		else if (ISOPERATOR(*str))
			push_token(tokens, 0, str++, NULL);
		else
			return (NULL);
	}
	return (tokens);
}

void			push_token(
		t_tokens_list *tokens, int as_number, char *operator, int *number)
{
	t_tokens *token;

	token = (t_tokens *)malloc(sizeof(t_tokens));
	token->next = NULL;
	if (as_number)
		token->token = init_number_token(*number);
	else
		token->token = new_operator_token(*operator);
	if (tokens->tail)
		tokens->tail->next = token;
	else
		tokens->head = token;
	tokens->tail = token;
}

t_token			*init_number_token(int number)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (new)
	{
		new->as_number = TRUE;
		new->data.number = number;
	}
	return (new);
}

t_token			*new_operator_token(char operator)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (new)
	{
		new->as_number = FALSE;
		new->data.operator = operator;
	}
	return (new);
}
