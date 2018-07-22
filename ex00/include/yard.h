/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yard.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-kir <mben-kir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 22:51:55 by mben-kir          #+#    #+#             */
/*   Updated: 2018/07/22 23:25:36 by mben-kir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YARD_H
# define YARD_H

# include "tokens.h"
# include "stack.h"

int		cmp_precedence(char op1, char op2);
int		op_index(char op);
void	parse_operator(t_token *operator, t_stack **operators, t_stack **rpn);
void	ft_syard(t_tokens_list *tokens, t_stack **operators, t_stack **rpn);

#endif
