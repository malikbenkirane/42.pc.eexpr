CC			=	gcc

CFLAGS		=	-g -Wall -Wextra -Werror 

CPFLAGS		=	-I./include/

SOURCES		=	src/eval_expr.c \
				src/ft_atoi_fwd.c \
				src/tokenize.c \
				src/stack.c \
				src/shunting_yard.c \
				src/main.c \
				src/ft_putchar.c \
				src/ft_putnbr.c

OBJS		=	$(SOURCES:.c=.o)

test:	$(OBJS)
		$(CC) $(CFLAGS) $(CPFLAGS) -o $@ $^

%.o:	%.c
		$(CC) $(CFLAGS) $(CPFLAGS) -c $< -o $@

clean:
		rm -f */*.o *.o

re:		clean test
