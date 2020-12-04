/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:23:47 by cisis             #+#    #+#             */
/*   Updated: 2020/12/04 16:51:51 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_processor.h"

static void	process_noflag(int width, char to_be_printed,
			int *num_printed)
{
	while (--width > 0)
		ft_printchar_count(' ', num_printed);
	ft_printchar_count(to_be_printed, num_printed);
}

static void	process_zeroflag(int width, char to_be_printed,
			int *num_printed)
{
	while (--width > 0)
		ft_printchar_count('0', num_printed);
	ft_printchar_count(to_be_printed, num_printed);
}

static void	process_minusflag(int width, char to_be_printed,
			int *num_printed)
{
	ft_printchar_count(to_be_printed, num_printed);
	while (--width > 0)
		ft_printchar_count(' ', num_printed);
}

void		ft_char_type(t_parsed format_info, va_list *argptr,
			int *num_printed)
{
	char	to_be_printed;
	int		width;

	width = format_info.width;
	to_be_printed = (char)va_arg(*argptr, int);
	if (width > 1)
	{
		if (format_info.flag == '-')
			process_minusflag(width, to_be_printed, num_printed);
		else if (format_info.flag == '0')
			process_zeroflag(width, to_be_printed, num_printed);
		else
			process_noflag(width, to_be_printed, num_printed);
	}
	else
		ft_printchar_count(to_be_printed, num_printed);
}
