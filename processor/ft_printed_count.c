/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:05:50 by cisis             #+#    #+#             */
/*   Updated: 2020/12/04 16:50:43 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_processor.h"

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
