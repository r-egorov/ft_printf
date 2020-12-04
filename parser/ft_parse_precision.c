/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:42:03 by cisis             #+#    #+#             */
/*   Updated: 2020/12/04 13:08:21 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

const char	*ft_parse_precision(const char *format,
								va_list *argptr, t_parsed *result)
{
	int		precsn;
	if (*format == '*')
	{
		if ((precsn = va_arg(*argptr, int)) < 0)
			precsn = 0;
		format++;
	}
	else
	{
		precsn = ft_atoi(format);
		while (*format >= '0' && *format <= '9')
			format++;
	}
	result->precision = precsn;
	return (format);
}
