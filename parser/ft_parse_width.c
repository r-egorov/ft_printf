/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:37:16 by cisis             #+#    #+#             */
/*   Updated: 2020/12/02 16:52:13 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_parse_width(const char *format, t_parsed *result)
{
	result->width = ft_atoi(format);
	while (*format >= '0' && *format <= '9')
		format++;
	return (format);
}
