/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cisis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:08:24 by cisis             #+#    #+#             */
/*   Updated: 2020/12/09 10:29:35 by cisis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROCESSOR_H
# define FT_PROCESSOR_H

# include "libft.h"
# include "ft_parser.h"
# include <stdarg.h>
# include <stdlib.h>

int		ft_process_format(t_parsed format_info, va_list *argptr,
		int *num_printed);
void	ft_printchar_count(char c, int *num_printed);
void	ft_printstr_count(char *str, int *num_printed);
void	ft_printnbrprcsn_count(long n, int *ptr_precision, int *num_printed);
void	ft_char_type(t_parsed format_info, va_list *argptr,
		int *num_printed);
void	ft_string_type(t_parsed format_info, va_list *argptr,
		int *num_printed);
int		ft_p_type(t_parsed format_info, va_list *argptr,
		int *num_printed);
void	ft_int_type(t_parsed format_info, va_list *argptr,
		int *num_printed);
void	ft_uint_type(t_parsed format_info, va_list *argptr,
		int *num_printed);
int		ft_hex_type(t_parsed format_info, va_list *argptr,
		int *num_printed);
void	ft_percent_type(t_parsed format_info, va_list *argptr,
		int *num_printed);
void	ft_unknown_type(t_parsed format_info, va_list *argptr,
		int *num_printed);

#endif
