#ifndef YARD_H
# define YARD_H

int		cmp_precedence(char op1, char op2);
int		op_index(char op);
void	parse_operator(t_token *operator, t_stack **operators, t_stack **rpn);
void	ft_syard(t_tokens_list *tokens, t_stack **operators, t_stack **rpn);

#endif
