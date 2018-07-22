#ifndef TOOLS_H
# define TOOLS_H

# define ISNUM(n) (n >= '0' && n<= '9')
# define ISSPACE1(c) (c == '\t' || c == '\n' || c == '\v')
# define ISSPACE2(c) (c == '\f' || c == '\r' || c == ' ')
# define ISSPACE(c) (ISSPACE1(c) || ISSPACE2(c))
# define TRUE 1
# define FALSE 0

int			ft_atoi_fwd(char **str);

#endif
