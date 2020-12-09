/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:42:03 by cisis             #+#    #+#             */
/*   Updated: 2020/12/09 15:38:07 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

const char	*ft_parse_precision(const char *format,
								va_list *argptr, t_parsed *result)
{
	int		precsn;

	if (*format == '*')
	{
		precsn = va_arg(*argptr, int);
		if (precsn < 0)
			precsn = (*(format + 1) == 's') ? -1 : 0;
		format++;
	}
	else if (*format >= '0' && *format <= '9')
	{
		precsn = ft_atoi(format);
		while (*format >= '0' && *format <= '9')
			format++;
	}
	else
		precsn = 0;
	result->precision = precsn;
	return (format);
}
