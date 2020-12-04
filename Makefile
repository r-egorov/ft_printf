NAME			=	libftprintf.a

INCLUDES		=	./includes/
PARCERDIR		=	./parser/
PROCESSORDIR	=	./processor/
FTPRINTFDIR		=	./ft_printf/

PARSERSRCS		=	$(PARCERDIR)ft_parser.c	\
					$(PARCERDIR)ft_parse_flags.c \
					$(PARCERDIR)ft_parse_width.c \
					$(PARCERDIR)ft_parse_precision.c \
					$(PARCERDIR)ft_parse_type.c
			
PROCESSORSRCS	=	$(PROCESSORDIR)ft_char_type.c \
					$(PROCESSORDIR)ft_string_type.c \
					$(PROCESSORDIR)ft_process_format.c \
					$(PROCESSORDIR)ft_printed_count.c

FTPRINTFSRCS	=	$(FTPRINTFDIR)ft_printf.c

SRCS			=	$(PARSERSRCS) $(PROCESSORSRCS) $(FTPRINTFSRCS)

OBJS			=	$(patsubst %.c,%.o,$(SRCS))

D_FILES			=	$(patsubst %.c,%.d,$(SRCS))

CCFLAGS			=	-Wall -Wextra -Werror

.c.o:				
					gcc $(CCFLAGS) -c $< -I $(INCLUDES) -o $(<:.c=.o) -MD

include	$(wildcard $(D_FILES))

lft:				
					cd libft && make 

partest:			$(OBJS)
					gcc -o test $? testing/parmain.c -L./libft -lft -I $(INCLUDES)

proctest:			$(OBJS)
					gcc -o test $? testing/procmain.c -L./libft -lft -I $(INCLUDES)

clean:				
					@ rm -f $(OBJS) $(D_FILES)

fclean:				clean
					@ rm -f $(NAME) test

re:					fclean all

.PHONY:				all clean fclean re
