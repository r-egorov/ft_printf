/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:40:04 by cisis             #+#    #+#             */
/*   Updated: 2020/12/02 17:00:32 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

typedef struct	s_parsed
{
	char	flag;
	int		width;
	int		precision;
	char	type;
	int		length;
}				t_parsed;

t_parsed		parse_format(const char *format);
const char		*ft_parse_precision(const char *format, t_parsed *result);
const char		*ft_parse_type(const char *format, t_parsed *result);
const char		*ft_parse_width(const char *format, t_parsed *result);
const char		*ft_parse_flags(const char *format, t_parsed *result);

#endif
