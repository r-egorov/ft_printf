/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:05:50 by cisis             #+#    #+#             */
/*   Updated: 2020/12/08 18:36:35 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_processor.h"

void	ft_printnbrprcsn_count(long n, int *ptr_precision, int *num_printed)
{
	int				nbrlen;
	unsigned int	val;

	nbrlen = ft_nbrlen(n);
	if (n < 0)
	{
		ft_printchar_count('-', num_printed);
		val = n * -1;
	}
	else
		val = n;
	while ((*ptr_precision)-- > nbrlen)
		ft_printchar_count('0', num_printed);
	if (val <= 9)
		ft_printchar_count(val + '0', num_printed);
	else
	{
		ft_printnbrprcsn_count(val / 10, ptr_precision, num_printed);
		ft_printnbrprcsn_count(val % 10, ptr_precision, num_printed);
	}
}

void	ft_printstr_count(char *str, int *num_printed)
{
	while (*str)
		ft_printchar_count(*str++, num_printed);
}

void	ft_printchar_count(char c, int *num_printed)
{
	ft_putchar_fd(c, 1);
	*num_printed += 1;
}
