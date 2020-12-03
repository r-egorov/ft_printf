NAME			=	libftprintf.a

INCLUDES		=	./includes/
PARCERDIR		=	./parser/

SRCS			=	$(PARCERDIR)ft_parser.c	\
					$(PARCERDIR)ft_parse_flags.c \
					$(PARCERDIR)ft_parse_width.c \
					$(PARCERDIR)ft_parse_precision.c \
					$(PARCERDIR)ft_parse_type.c

OBJS			=	$(patsubst %.c,%.o,$(SRCS))

D_FILES			=	$(patsubst %.c,%.d,$(SRCS))

CCFLAGS			=	-Wall -Wextra -Werror

.c.o:				
					gcc $(CCFLAGS) -c $< -I $(INCLUDES) -o $(<:.c=.o) -MD

include	$(wildcard $(D_FILES))

partest:				$(OBJS)
					gcc -o test $? testing/main.c -L./libft -lft -I $(INCLUDES)

clean:				
					@ rm -f $(OBJS) $(D_FILES)

fclean:				clean
					@ rm -f $(NAME) test

re:					fclean all

.PHONY:				all clean fclean re
