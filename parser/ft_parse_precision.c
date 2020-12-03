/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:42:03 by cisis             #+#    #+#             */
/*   Updated: 2020/12/03 13:03:46 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

const char	*ft_parse_precision(const char *format,
								va_list *argptr, t_parsed *result)
{
	if (*format == '*')
	{
		result->precision = va_arg(*argptr, int);
		format++;
	}
	else
	{
		result->precision = ft_atoi(format);
		while (*format >= '0' && *format <= '9')
			format++;
	}
	return (format);
}
