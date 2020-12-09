/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:16:48 by cisis             #+#    #+#             */
/*   Updated: 2020/12/09 15:30:45 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_processor.h"
#include <stdio.h> //FIXME

static void	calculate_values(t_parsed format_info, char *string_to_print,
			int *field_len, int *string_len)
{
	*string_len = ft_strlen(string_to_print);
	*field_len = *string_len;
	if (format_info.precision != -1 && format_info.precision < *field_len)
		*field_len = format_info.precision;
}

static void	process_noflag(t_parsed format_info,
			char *string_to_print, int *num_printed)
{
	int		field_len;
	int		string_len;

	calculate_values(format_info, string_to_print, &field_len, &string_len);
	while (format_info.width-- > field_len)
		ft_printchar_count(' ', num_printed);
	while (field_len-- > 0)
		ft_printchar_count(*string_to_print++, num_printed);
}

static void	process_zeroflag(t_parsed format_info,
			char *string_to_print, int *num_printed)
{
	int		field_len;
	int		string_len;

	calculate_values(format_info, string_to_print, &field_len, &string_len);
	while (format_info.width-- > field_len)
		ft_printchar_count('0', num_printed);
	while (field_len-- > 0)
		ft_printchar_count(*string_to_print++, num_printed);
}

static void	process_minusflag(t_parsed format_info,
			char *string_to_print, int *num_printed)
{
	int		field_len;
	int		initial_field_len;
	int		string_len;

	calculate_values(format_info, string_to_print, &field_len, &string_len);
	initial_field_len = field_len;
	while (field_len-- > 0)
		ft_printchar_count(*string_to_print++, num_printed);
	while (format_info.width-- > initial_field_len)
		ft_printchar_count(' ', num_printed);
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
