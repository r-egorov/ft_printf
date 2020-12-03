/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:00:30 by cisis             #+#    #+#             */
/*   Updated: 2020/12/03 13:02:46 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include "libft.h"
# include <stdarg.h>

typedef struct	s_parsed
{
	char	flag;
	int		width;
	int		precision;
	char	type;
	int		length;
}				t_parsed;

t_parsed		ft_parse_format(const char *format, va_list *argptr);
const char		*ft_parse_type(const char *format, t_parsed *result);
const char		*ft_parse_width(const char *format,
								va_list *argptr, t_parsed *result);
const char		*ft_parse_precision(const char *format,
									va_list *argptr, t_parsed *result);
const char		*ft_parse_flags(const char *format, t_parsed *result);

#endif
