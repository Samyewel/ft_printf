/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:39:01 by swilliam          #+#    #+#             */
/*   Updated: 2022/08/03 14:15:51 by swilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** decimal_left_padding:
** - Called within print_decimal_left.
** - Prints the respective padding to the left of the converted decimal,
**   therefore aligning it to the right.
*/

static void	decimal_left_padding(t_printf *flags, int u_length)
{
	char	padding;

	if ((flags->zero_padding && !flags->precision) || flags->precision)
		padding = '0';
	else
		padding = ' ';
	if (flags->precision)
	{
		while (flags->width-- > flags->precision)
			flags->total_length += write(flags->fd, " ", 1);
		while (flags->precision-- > u_length)
			flags->total_length += write(flags->fd, "0", 1);
	}
	else
		while (flags->width-- > u_length)
			flags->total_length += write(flags->fd, &padding, 1);
}

/*
** printf_decimal_left:
** - Handles the conversion for when no '-' flag is used.
** - Uses decimal_left_padding to handle padding.
*/

static void	print_decimal_left(t_printf *flags, int u_length
, char *utoa_res)
{
	decimal_left_padding(flags, u_length);
	flags->total_length += write(flags->fd, utoa_res, ft_strlen(utoa_res));
}

/*
** print_decimal_right:
** - Handles the conversion for when the '-' flag is used.
** - Prints the respective padding to the right of the converted decimal,
**   therefore aligning it to the left.
*/

static void	print_decimal_right(t_printf *flags, int u_length
, char *utoa_res)
{
	while (u_length++ < flags->precision)
		flags->total_length += write(flags->fd, "0", 1);
	flags->total_length += write(flags->fd, utoa_res, ft_strlen(utoa_res));
	while (flags->width-- >= u_length)
		flags->total_length += write(flags->fd, " ", 1);
}

/*
** print_decimal:
** - Converts the given decimal into a string using utoa.
** - If a '-' flag is used, the conversion will align the string to the left,
**   otherwise it will align to the right.
*/

void	print_decimal(t_printf *flags, uintmax_t u)
{
	char	*utoa_res;
	int		u_length;

	utoa_res = ft_printf_utoa_base(flags, u, 10);
	u_length = ft_strlen(utoa_res);
	if (flags->dash)
		print_decimal_right(flags, u_length, utoa_res);
	else
		print_decimal_left(flags, u_length, utoa_res);
	ft_strdel(&utoa_res);
}
