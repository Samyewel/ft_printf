/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:45:42 by swilliam          #+#    #+#             */
/*   Updated: 2022/08/03 15:32:27 by swilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** octal_left_padding:
** - Handles the padding necessary padding for when printing to the left
**   of the octal number.
*/

static void	octal_left_padding(t_printf *flags, int o_length)
{
	char	padding;

	if ((flags->zero_padding && !flags->precision) || flags->precision)
		padding = '0';
	else
		padding = ' ';
	if (flags->precision)
	{
		if (flags->plus || flags->zero_padding)
			flags->width--;
		while (flags->width-- > o_length)
			flags->total_length += write(flags->fd, &padding, 1);
	}
	else
		while (flags->width-- > o_length)
			flags->total_length += write(flags->fd, &padding, 1);
}

/*
** print_octal_left:
** - Handles the conversion for when no '-' flag is used.
** - Prints the respective padding to the left of the converted octal number,
**   therefore aligning it to the right.
*/

static void	print_octal_left(t_printf *flags, uintmax_t o, int o_length
, char *utoa_res)
{
	if ((flags->hash && o != 0) && flags->zero_padding)
		flags->total_length += write(1, "0", 1);
	octal_left_padding(flags, o_length);
	while (o_length++ < flags->precision)
		flags->total_length += write(flags->fd, "0", 1);
	if ((flags->hash && o != 0) && !flags->zero_padding)
		flags->total_length += write(1, "0", 1);
	flags->total_length += write(flags->fd, utoa_res, ft_strlen(utoa_res));
}
/*
** print_octal_right:
** - Handles the conversion for when the '-' flag is used.
** - Prints the respective padding to the right of the converted octal number,
**   therefore aligning it to the left.
*/

static void	print_octal_right(t_printf *flags, uintmax_t o, int o_length
, char *utoa_res)
{
	if ((flags->hash && o != 0) && flags->dash)
		flags->total_length += write(1, "0", 1);
	while (o_length++ < flags->precision)
			flags->total_length += write(flags->fd, "0", 1);
	flags->total_length += write(flags->fd, utoa_res, ft_strlen(utoa_res));
	while (flags->width-- >= o_length)
			flags->total_length += write(flags->fd, " ", 1);
}
/*
** print_octal:
** - If the input value is 0 and no precision is specified, the width is
**   handled seperately from other calculations.
** - If a '-' flag is used, the conversion will align the string to the left,
**   otherwise it will align to the right.
*/

void	print_octal(t_printf *flags, uintmax_t o)
{
	char	*utoa_res;
	int		o_length;

	if (o == 0 && flags->period && !flags->precision)
	{
		while (flags->width--)
			flags->total_length += write(flags->fd, " ", 1);
		if (flags->hash)
			flags->total_length += write(1, "0", 1);
		if ((!flags->dash) || (flags->dash && !flags->hash))
			return ;
	}
	utoa_res = ft_printf_utoa_base(flags, o, 8);
	o_length = ft_strlen(utoa_res);
	o_length += (flags->hash && o != 0);
	if (flags->dash)
		print_octal_right(flags, o, o_length, utoa_res);
	else
		print_octal_left(flags, o, o_length, utoa_res);
	ft_strdel(&utoa_res);
}
