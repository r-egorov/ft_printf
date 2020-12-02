/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:46:04 by cisis             #+#    #+#             */
/*   Updated: 2020/12/02 17:02:58 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_parse_type(const char *format, t_parsed *result)
{
	if (*format)
	{
		result->type = *format;
		format++;
	}
	return (format);
}
