/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-kir <mben-kir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 22:49:27 by mben-kir          #+#    #+#             */
/*   Updated: 2018/07/22 23:02:08 by mben-kir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

/*
** The expression grammar should respect the following precedence rules :
**
** precedence left +, -
** precedence left *, /
** precedence left %
**
** The grammar itself is :
**
** X -> E$
** E -> E + F | E - F | T
** F -> F * G | F / G | T
** G -> G % H | T
** T -> (E) | number
**
** Tokens are the following :
** +, -, *, /, (, ), %, number (see atoi)
*/

# define OPERATORS "+-*/%()"
# define PLUS	0
# define MINUS	1
# define TIMES	2
# define DIV	3
# define MOD	4
# define LPAR	5
# define RPAR	6
# define PRECEDENCE "2233400"

# define ISOP1(o) 		(o == OPERATORS[PLUS] || o == OPERATORS[MINUS])
# define ISOP2(o) 		(o == OPERATORS[TIMES] || o == OPERATORS[DIV])
# define ISOP3(o) 		(o == OPERATORS[MOD])
# define ISOP4(o) 		(o == OPERATORS[LPAR] || o == OPERATORS[RPAR])
# define ISOPERATOR(o)	(ISOP1(o) || ISOP2(o) || ISOP3(o) || ISOP4(o))

typedef short		t_bool;

typedef union		u_token
{
	int				number;
	char			operator;
}					t_token_data;

typedef struct		s_token
{
	t_token_data	data;
	t_bool			as_number;
}					t_token;

typedef struct		s_tokens
{
	t_token			*token;
	struct s_tokens *next;
}					t_tokens;

typedef struct		s_tokens_list
{
	t_tokens		*head;
	t_tokens		*tail;
}					t_tokens_list;

t_tokens_list		*tokenize(char *str);
t_token				*init_number_token(int number);
t_token				*new_operator_token(char operator);
void				push_token(
		t_tokens_list *tokens, int as_number, char *operator, int *number);

#endif
