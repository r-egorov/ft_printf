/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:37:16 by cisis             #+#    #+#             */
/*   Updated: 2020/12/03 13:04:34 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

const char	*ft_parse_width(const char *format,
							va_list *argptr, t_parsed *result)
{
	int		width_res;

	if (*format == '*')
	{
		width_res = va_arg(*argptr, int);
		if (width_res < 0)
		{
			result->flag = '-';
			width_res = width_res * -1;
		}
		format++;
	}
	else
	{
		width_res = ft_atoi(format);
		while (*format >= '0' && *format <= '9')
			format++;
	}
	result->width = width_res;
	return (format);
}
