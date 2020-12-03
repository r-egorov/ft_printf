/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:46:04 by cisis             #+#    #+#             */
/*   Updated: 2020/12/03 13:03:54 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

const char	*ft_parse_type(const char *format, t_parsed *result)
{
	if (*format)
	{
		result->type = *format;
		format++;
	}
	return (format);
}
