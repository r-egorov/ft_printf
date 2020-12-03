/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:04:21 by cisis             #+#    #+#             */
/*   Updated: 2020/12/03 14:20:16 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_processor.h"

int		ft_process_format(t_parsed format_info, va_list *argptr)
{
	format_info.type == 'c' ? : (ft_char_type(format_info, argptr));
	format_info.type == 's' ? : (ft_string_type(format_info, argptr));
	format_info.type == 'p' ? : (ft_p_type(format_info, argptr));
	format_info.type == 'd' ? : (ft_di_type(format_info, argptr));
	format_info.type == 'i' ? : (ft_di_type(format_info, argptr));
	format_info.type == 'u' ? : (ft_u_type(format_info, argptr));
	format_info.type == 'x' ? : (ft_hex_type(format_info, argptr));
	format_info.type == 'X' ? : (ft_hex_type(format_info, argptr));
	format_info.type == '%' ? : (ft_percent_type(format_info, argptr));
}
