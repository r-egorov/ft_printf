/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:05:50 by cisis             #+#    #+#             */
/*   Updated: 2020/12/03 17:58:22 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_processor.h"

int		ft_printchar_count(char c)
{
	static int	num_printed;
	ft_putchar_fd(c, 1);
	num_printed += 1;
	return (num_printed);
}
