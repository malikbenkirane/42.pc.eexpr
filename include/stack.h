#ifndef STACK_H
# define STACK_H

# include "tokens.h"

// TODO add free stack method

typedef struct		s_stack
{
	t_token			*top;
	struct s_stack	*stack;
}					t_stack;

t_stack	*stack_init(t_token *top);
t_token	*stack_pop(t_stack **stack);
void	stack_push(t_token *token, t_stack **stack);

#endif
