/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:44:40 by cisis             #+#    #+#             */
/*   Updated: 2020/12/11 17:52:31 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		argptr;
	t_parsed	format_info;
	int			num_printed;

	num_printed = 0;
	va_start(argptr, format);
	while (*format)
	{
		if (*format == '%')
		{
			format_info = ft_parse_format(++format, &argptr);
			if (ft_process_format(format_info, &argptr, &num_printed) == -1)
			{
				num_printed = -1;
				break ;
			}
			format = format + (format_info.length);
		}
		else
			ft_printchar_count(*format++, &num_printed);
	}
	va_end(argptr);
	return (num_printed);
}
