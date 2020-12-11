/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:17:24 by cisis             #+#    #+#             */
/*   Updated: 2020/12/11 13:14:38 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_processor.h"

static void	calculate_values(t_parsed format_info, char *address_hex,
			int *field_len, int *address_len)
{
	*address_len = ft_strlen(address_hex);
	*field_len = *address_len;
	if (format_info.precision > *field_len)
		*field_len = format_info.precision;
}

static void	process_minusflag(t_parsed format_info,
			char *address_hex, int *num_printed)
{
	int				field_len;
	int				address_len;

	calculate_values(format_info, address_hex, &field_len, &address_len);
	ft_printstr_count("0x", num_printed);
	while (format_info.precision-- > address_len)
		ft_printchar_count('0', num_printed);
	ft_printstr_count(address_hex, num_printed);
	while (format_info.width-- > field_len + 2)
		ft_printchar_count(' ', num_printed);
}

static void	process_zeroflag(t_parsed format_info,
			char *address_hex, int *num_printed)
{
	int				field_len;
	int				address_len;

	calculate_values(format_info, address_hex, &field_len, &address_len);
	if (format_info.width > field_len && format_info.precision == -1)
	{
		ft_printstr_count("0x", num_printed);
		while (format_info.width-- > field_len + 2)
			ft_printchar_count('0', num_printed);
		ft_printstr_count(address_hex, num_printed);
	}
	else
	{
		while (format_info.width-- > field_len + 2)
			ft_printchar_count(' ', num_printed);
		ft_printstr_count("0x", num_printed);
		while (format_info.precision-- > address_len)
			ft_printchar_count('0', num_printed);
		ft_printstr_count(address_hex, num_printed);
	}
}

static void	process_noflag(t_parsed format_info,
			char *address_hex, int *num_printed)
{
	int				field_len;
	int				address_len;

	calculate_values(format_info, address_hex, &field_len, &address_len);
	while (format_info.width-- > field_len + 2)
		ft_printchar_count(' ', num_printed);
	ft_printstr_count("0x", num_printed);
	while (format_info.precision-- > address_len)
		ft_printchar_count('0', num_printed);
	ft_printstr_count(address_hex, num_printed);
}

int			ft_p_type(t_parsed format_info, va_list *argptr,
			int *num_printed)
{
	unsigned long	pointer_to_print;
	char			*address_hex;

	pointer_to_print = (unsigned long)va_arg(*argptr, void*);
	if (pointer_to_print == 0 && format_info.precision == 0)
		address_hex = ft_strdup("");
	else
	{
		if (!(address_hex = ft_lutoa_base(pointer_to_print,
						"0123456789abcdef")))
			return (-1);
	}
	if (format_info.flag == '-')
		process_minusflag(format_info, address_hex, num_printed);
	else if (format_info.flag == '0')
		process_zeroflag(format_info, address_hex, num_printed);
	else
		process_noflag(format_info, address_hex, num_printed);
	free(address_hex);
	return (0);
}
