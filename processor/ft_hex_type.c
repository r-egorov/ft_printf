/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:42:51 by cisis             #+#    #+#             */
/*   Updated: 2020/12/11 13:15:18 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_processor.h"

static void	calculate_values(t_parsed format_info, char *str_nbr_hex,
			int *field_len, int *str_nbr_hex_len)
{
	*str_nbr_hex_len = ft_strlen(str_nbr_hex);
	*field_len = *str_nbr_hex_len;
	if (format_info.precision > *field_len)
		*field_len = format_info.precision;
}

static void	process_minusflag(t_parsed format_info, char *str_nbr_hex,
			int *num_printed)
{
	int				field_len;
	int				initial_field_len;
	int				str_nbr_hex_len;

	calculate_values(format_info, str_nbr_hex, &field_len, &str_nbr_hex_len);
	initial_field_len = field_len;
	while (field_len-- > str_nbr_hex_len)
		ft_printchar_count('0', num_printed);
	ft_printstr_count(str_nbr_hex, num_printed);
	while (format_info.width-- > initial_field_len)
		ft_printchar_count(' ', num_printed);
}

static void	process_zeroflag(t_parsed format_info, char *str_nbr_hex,
			int *num_printed)
{
	int				field_len;
	int				str_nbr_hex_len;

	calculate_values(format_info, str_nbr_hex, &field_len, &str_nbr_hex_len);
	while (format_info.width-- > field_len)
		ft_printchar_count('0', num_printed);
	ft_printstr_count(str_nbr_hex, num_printed);
}

static void	process_noflag(t_parsed format_info, char *str_nbr_hex,
			int *num_printed)
{
	int				field_len;
	int				str_nbr_hex_len;

	calculate_values(format_info, str_nbr_hex, &field_len, &str_nbr_hex_len);
	while (format_info.width-- > field_len)
		ft_printchar_count(' ', num_printed);
	while (field_len-- > str_nbr_hex_len)
		ft_printchar_count('0', num_printed);
	ft_printstr_count(str_nbr_hex, num_printed);
}

int			ft_hex_type(t_parsed format_info, va_list *argptr,
			int *num_printed)
{
	unsigned int	nbr_to_print;
	char			*str_nbr_hex;
	const char		*base;

	if (format_info.type == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	nbr_to_print = va_arg(*argptr, unsigned int);
	if (nbr_to_print == 0 && format_info.precision == 0)
		str_nbr_hex = ft_strdup("");
	else
	{
		if (!(str_nbr_hex = ft_lutoa_base((unsigned long)nbr_to_print, base)))
			return (-1);
	}
	if (format_info.flag == '-')
		process_minusflag(format_info, str_nbr_hex, num_printed);
	else if (format_info.flag == '0' && format_info.precision == -1)
		process_zeroflag(format_info, str_nbr_hex, num_printed);
	else
		process_noflag(format_info, str_nbr_hex, num_printed);
	free(str_nbr_hex);
	return (0);
}
