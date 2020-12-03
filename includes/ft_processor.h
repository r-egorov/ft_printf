/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:08:24 by cisis             #+#    #+#             */
/*   Updated: 2020/12/03 15:01:02 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROCESSOR_H
# define FT_PROCESSOR_H

# include "libft.h"
# include "ft_parser.h"
# include <stdarg.h>

int		ft_printchar_count(char c);
int		ft_char_type(t_parsed format_info, va_list *argptr);
int		ft_string_type(t_parsed format_info, va_list *argptr);
int		ft_p_type(t_parsed format_info, va_list *argptr);
int		ft_di_type(t_parsed format_info, va_list *argptr);
int		ft_u_type(t_parsed format_info, va_list *argptr);
int		ft_hex_type(t_parsed format_info, va_list *argptr);
int		ft_percent_type(t_parsed format_info, va_list *argptr);

#endif
