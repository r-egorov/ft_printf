/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:04:21 by cisis             #+#    #+#             */
/*   Updated: 2020/12/04 15:18:57 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_processor.h"

int		ft_process_format(t_parsed format_info, va_list *argptr,
		int *num_printed)
{
	if (format_info.type == 'c')
		ft_char_type(format_info, argptr, num_printed);
	if (format_info.type == 's')
		ft_string_type(format_info, argptr, num_printed);
	/*if (format_info.type == 'p')
		return (ft_p_type(format_info, argptr));
	if (format_info.type == 'd')
		return (ft_di_type(format_info, argptr));
	if (format_info.type == 'i')
		return (ft_di_type(format_info, argptr));
	if (format_info.type == 'u')
		return (ft_u_type(format_info, argptr));
	if (format_info.type == 'x')
		return (ft_hex_type(format_info, argptr));
	if (format_info.type == 'X')
		return (ft_hex_type(format_info, argptr));
	if (format_info.type == '%')
		return (ft_percent_type(format_info, argptr));
	return (ft_unknown_type(format_info, argptr));*/
	return (0);
}
