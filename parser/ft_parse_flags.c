/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:24:08 by cisis             #+#    #+#             */
/*   Updated: 2020/12/02 17:00:42 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_flag(const char format)
{
	if (format == '-' || format == '0')
		return (1);
	return (0);
}

const char	*ft_parse_flags(const char *format, t_parsed *result)
{
	while (is_flag(*format))
	{
		if ((*format == '0' && (*result).flag != '-'))
			result->flag = '0';
		else if (*format == '-')
			result->flag = '-';
		format++;
	}
	return (format);
}
