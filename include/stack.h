/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-kir <mben-kir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 22:50:41 by mben-kir          #+#    #+#             */
/*   Updated: 2018/07/22 22:51:33 by mben-kir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "tokens.h"

/*
** TODO add free stack method
*/

typedef struct		s_stack
{
	t_token			*top;
	struct s_stack	*stack;
}					t_stack;

t_stack				*stack_init(t_token *top);
t_token				*stack_pop(t_stack **stack);
void				stack_push(t_token *token, t_stack **stack);

#endif
