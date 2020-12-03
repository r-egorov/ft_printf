/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:44:40 by cisis             #+#    #+#             */
/*   Updated: 2020/12/03 18:06:50 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		argptr;
	t_parsed	format_info;
	int			num_printed;

	va_start(argptr, format);
	while (*format)
	{
		if (*format == '%')
		{
			format_info = ft_parse_format(++format, &argptr);
			if (ft_process_format(format_info, &argptr) == -1)
				break ;
			format = format + (format_info.length);
		}
		else
			num_printed = ft_printchar_count(*format++);
	}
	va_end(argptr);
	return (num_printed);
}
