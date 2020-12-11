# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cisis <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/09 16:35:10 by cisis             #+#    #+#              #
#    Updated: 2020/12/09 17:09:26 by cisis            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a
LIBFTNAME		=	libft.a

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
					$(PROCESSORDIR)ft_p_type.c \
					$(PROCESSORDIR)ft_hex_type.c \
					$(PROCESSORDIR)ft_int_type.c \
					$(PROCESSORDIR)ft_uint_type.c \
					$(PROCESSORDIR)ft_percent_type.c \
					$(PROCESSORDIR)ft_process_format.c \
					$(PROCESSORDIR)ft_printed_count.c

FTPRINTFSRCS	=	$(FTPRINTFDIR)ft_printf.c

SRCS			=	$(PARSERSRCS) $(PROCESSORSRCS) $(FTPRINTFSRCS)

OBJS			=	$(patsubst %.c,%.o,$(SRCS))

D_FILES			=	$(patsubst %.c,%.d,$(SRCS))

CCFLAGS			=	-Wall -Wextra -Werror

.c.o:				
					@ gcc $(CCFLAGS) -c $< -I $(INCLUDES) -o $(<:.c=.o) -MD

include	$(wildcard $(D_FILES))



all:				$(NAME)

lft:				
					@ echo "Compiling libft.a..."
					@ cd libft && make all && make clean && mv libft.a ../libftprintf.a
					@ echo "Compiling libft.a done."

$(NAME):			$(OBJS)
					@ make lft
					@ echo "Archiving into libftprintf.a..."
					@ ar rcs $(NAME) $?
					@ echo "Archiving into libftprintf.a done."

clean:				
					@ rm -f $(OBJS) $(D_FILES) $(LIBFTNAME)
					@ echo "Cleaning done."

fclean:				clean
					@ rm -f $(NAME) test
					@ echo "libftprintf.a deleted."

re:					fclean all

.PHONY:				all clean fclean re lft
