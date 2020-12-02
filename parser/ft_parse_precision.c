/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:42:03 by cisis             #+#    #+#             */
/*   Updated: 2020/12/02 16:51:45 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_parse_precision(const char *format, t_parsed *result)
{
	result->precision = ft_atoi(format);
	while (*format >= '0' && *format <= '9')
		format++;
	return (format);
}
