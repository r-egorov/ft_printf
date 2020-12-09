/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:04:21 by cisis             #+#    #+#             */
/*   Updated: 2020/12/09 11:09:25 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_processor.h"

int		ft_process_format(t_parsed format_info, va_list *argptr,
		int *num_printed)
{
	if (format_info.type == 'c')
		ft_char_type(format_info, argptr, num_printed);
	else if (format_info.type == 's')
		ft_string_type(format_info, argptr, num_printed);
	else if (format_info.type == 'p')
		return (ft_p_type(format_info, argptr, num_printed));
	else if (format_info.type == 'd')
		ft_int_type(format_info, argptr, num_printed);
	else if (format_info.type == 'i')
		ft_int_type(format_info, argptr, num_printed);
	else if (format_info.type == 'u')
		ft_uint_type(format_info, argptr, num_printed);
	else if (format_info.type == 'x')
		return (ft_hex_type(format_info, argptr, num_printed));
	else if (format_info.type == 'X')
		return (ft_hex_type(format_info, argptr, num_printed));
	else if (format_info.type == '%')
		ft_percent_type(format_info, num_printed);
	return (0);
}
