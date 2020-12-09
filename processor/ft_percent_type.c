/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:23:47 by cisis             #+#    #+#             */
/*   Updated: 2020/12/09 11:05:05 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_processor.h"

static void	process_noflag(int width, int *num_printed)
{
	while (--width > 0)
		ft_printchar_count(' ', num_printed);
	ft_printchar_count('%', num_printed);
}

static void	process_zeroflag(int width, int *num_printed)
{
	while (--width > 0)
		ft_printchar_count('0', num_printed);
	ft_printchar_count('%', num_printed);
}

static void	process_minusflag(int width, int *num_printed)
{
	ft_printchar_count('%', num_printed);
	while (--width > 0)
		ft_printchar_count(' ', num_printed);
}

void		ft_percent_type(t_parsed format_info, int *num_printed)
{
	int		width;

	width = format_info.width;
	if (width > 1)
	{
		if (format_info.flag == '-')
			process_minusflag(width, num_printed);
		else if (format_info.flag == '0')
			process_zeroflag(width, num_printed);
		else
			process_noflag(width, num_printed);
	}
	else
		ft_printchar_count('%', num_printed);
}
