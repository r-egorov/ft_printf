/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:16:48 by cisis             #+#    #+#             */
/*   Updated: 2020/12/04 17:21:05 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_processor.h"

static void	process_noflag(t_parsed format_info,
			char *string_to_print, int *num_printed)
{
	int		field_len;
	int		string_len;

	string_len = ft_strlen(string_to_print);
	field_len = string_len;
	if (format_info.precision < field_len && format_info.precision != -1)
		field_len = format_info.precision;
	if (format_info.width > field_len)
		field_len = format_info.width;
	if (format_info.precision != -1)
		string_len = format_info.precision;
	while ((field_len - string_len) > 0)
	{
		ft_printchar_count(' ', num_printed);
		field_len--;
	}
	while (string_len-- > 0)
		ft_printchar_count(*string_to_print++, num_printed);
}

static void	process_zeroflag(t_parsed format_info,
			char *string_to_print, int *num_printed)
{
	int		field_len;
	int		string_len;

	string_len = ft_strlen(string_to_print);
	field_len = string_len;
	if (format_info.precision < field_len && format_info.precision != -1)
		field_len = format_info.precision;
	if (format_info.width > field_len)
		field_len = format_info.width;
	if (format_info.precision != -1)
		string_len = format_info.precision;
	while ((field_len - string_len) > 0)
	{
		ft_printchar_count('0', num_printed);
		field_len--;
	}
	while (string_len-- > 0)
		ft_printchar_count(*string_to_print++, num_printed);
}

static void	process_minusflag(t_parsed format_info,
			char *string_to_print, int *num_printed)
{
	int		field_len;

	field_len = ft_strlen(string_to_print);
	if (format_info.precision < field_len && format_info.precision != -1)
		field_len = format_info.precision;
	if (format_info.width > field_len)
		field_len = format_info.width;
	while (field_len > 0)
	{
		while (*string_to_print &&
				(format_info.precision > 0 || format_info.precision == -1))
		{
			ft_printchar_count(*string_to_print++, num_printed);
			field_len--;
			if (format_info.precision != -1)
				format_info.precision--;
		}
		ft_printchar_count(' ', num_printed);
		field_len--;
	}
}

void		ft_string_type(t_parsed format_info, va_list *argptr,
			int *num_printed)
{
	char	*string_to_print;

	string_to_print = va_arg(*argptr, char*);
	if (!string_to_print)
		string_to_print = "(null)";
	if (format_info.flag == '-')
		process_minusflag(format_info, string_to_print, num_printed);
	else if (format_info.flag == '0')
		process_zeroflag(format_info, string_to_print, num_printed);
	else
		process_noflag(format_info, string_to_print, num_printed);
}
