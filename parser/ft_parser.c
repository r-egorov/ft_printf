/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:55:27 by cisis             #+#    #+#             */
/*   Updated: 2020/12/03 13:04:57 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static int	is_flag(const char format)
{
	if (format == '-' || format == '0')
		return (1);
	return (0);
}

static void	init_structure(t_parsed *new)
{
	new->flag = 0;
	new->width = 0;
	new->precision = -1;
	new->type = 0;
	new->length = 0;
}

t_parsed	ft_parse_format(const char *format, va_list *argptr)
{
	t_parsed	result;
	const char	*format_start;

	init_structure(&result);
	format_start = format;
	if (is_flag(*format))
		format = ft_parse_flags(format, &result);
	if ((*format >= '0' && *format <= '9') || (*format == '*'))
		format = ft_parse_width(format, argptr, &result);
	if (*format == '.')
		format = ft_parse_precision(++format, argptr, &result);
	format = ft_parse_type(format, &result);
	result.length = format - format_start;
	return (result);
}
