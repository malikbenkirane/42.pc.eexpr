#ifndef EVAL_EXPR_H
# define EVAL_EXPR_H

#include "stack.h"

int	eval_expr(char *str);
int compute_rpn(t_stack **rpn);
void compute_op(int number1, int number2, char operator, t_stack **cstack);

#endif

