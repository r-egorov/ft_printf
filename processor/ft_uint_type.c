/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:14:27 by cisis             #+#    #+#             */
/*   Updated: 2020/12/09 10:33:33 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_processor.h"

static void	calculate_values(t_parsed format_info, int nbr_to_print,
			int *field_len, int *nbrlen)
{
	*nbrlen = ft_nbrlen(nbr_to_print);
	*field_len = *nbrlen;
	if (format_info.precision > *field_len)
		*field_len = format_info.precision;
}

static void	process_minusflag(t_parsed format_info, unsigned int nbr_to_print,
			int *num_printed)
{
	int		field_len;
	int		nbrlen;

	calculate_values(format_info, nbr_to_print, &field_len, &nbrlen);
	ft_printnbrprcsn_count((long)nbr_to_print, &format_info.precision,
							num_printed);
	while (format_info.width-- > field_len)
		ft_printchar_count(' ', num_printed);
}

static void	process_zeroflag(t_parsed format_info, unsigned int nbr_to_print,
			int *num_printed)
{
	ft_printnbrprcsn_count((long)nbr_to_print, &format_info.width,
							num_printed);
}

static void	process_noflag(t_parsed format_info, unsigned int nbr_to_print,
			int *num_printed)
{
	int		field_len;
	int		nbrlen;

	calculate_values(format_info, nbr_to_print, &field_len, &nbrlen);
	while (format_info.width-- > field_len)
		ft_printchar_count(' ', num_printed);
	ft_printnbrprcsn_count((long)nbr_to_print, &format_info.precision,
							num_printed);
}

void		ft_uint_type(t_parsed format_info, va_list *argptr,
			int *num_printed)
{
	unsigned int	nbr_to_print;

	nbr_to_print = va_arg(*argptr, unsigned int);
	if (format_info.flag == '-')
		process_minusflag(format_info, nbr_to_print, num_printed);
	else if (format_info.flag == '0' && format_info.precision == -1)
		process_zeroflag(format_info, nbr_to_print, num_printed);
	else
		process_noflag(format_info, nbr_to_print, num_printed);
}
