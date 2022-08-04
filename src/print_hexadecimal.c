/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:18:43 by swilliam          #+#    #+#             */
/*   Updated: 2022/08/03 14:09:56 by swilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** hex_prefix:
** - Prints the respective prefix for the number given depending on if the 'x'
**   or 'X' flag is used.
** - If the input is a pointer address, then we print an '0x' prefix.
*/

static void	hex_prefix(t_printf *flags, uintmax_t x)
{
	if (x != 0 || flags->format == 'p')
	{
		if (flags->format == 'x' || flags->format == 'p')
			flags->total_length += write(flags->fd, "0x", 2);
		else if (flags->format == 'X')
			flags->total_length += write(flags->fd, "0X", 2);
	}
}

/*
** hex_left_padding:
** - Handles the padding necessary padding for when printing to the left
**   of the hexadecimal.
*/

static void	hex_left_padding(t_printf *flags, int x_length)
{
	char	padding;

	if (flags->zero_padding && !flags->precision)
		padding = '0';
	else
		padding = ' ';
	if (flags->precision)
	{
		if (flags->plus || flags->zero_padding)
			flags->width--;
		while (flags->width-- > x_length)
			flags->total_length += write(flags->fd, &padding, 1);
	}
	else
		while (flags->width-- > x_length)
			flags->total_length += write(flags->fd, &padding, 1);
}

/*
** print_hex_left:
** - Handles the conversion for when no '-' flag is used.
** - Prints the respective padding to the left of the converted hexadecimal,
**   therefore aligning it to the right.
*/

static void	print_hex_left(t_printf *flags, uintmax_t x, int x_length,
char *utoa_res)
{
	if (flags->hash && flags->zero_padding)
		hex_prefix(flags, x);
	hex_left_padding(flags, x_length);
	if ((flags->hash && !flags->zero_padding) || flags->format == 'p')
		hex_prefix(flags, x);
	flags->total_length += write(flags->fd, utoa_res, ft_strlen(utoa_res));
}

/*
** print_hex_right:
** - Handles the conversion for when the '-' flag is used.
** - Prints the respective padding to the right of the converted hexadecimal,
**   therefore aligning it to the left.
*/

static void	print_hex_right(t_printf *flags, uintmax_t x, int x_length,
char *utoa_res)
{
	if (flags->hash || flags->format == 'p')
		hex_prefix(flags, x);
	while (x_length++ < flags->precision)
		flags->total_length += write(flags->fd, "0", 1);
	flags->total_length += write(flags->fd, utoa_res, ft_strlen(utoa_res));
	while (flags->width-- >= x_length)
		flags->total_length += write(flags->fd, " ", 1);
}

/*
** print_hexadecimal:
** - Prints the given input as a hexidecimal value.
** - Also takes a pointer address as an input to be printed with a prefix.
** - If a '-' flag is used, the conversion will align the string to the left,
**   otherwise it will align to the right.
*/

void	print_hexadecimal(t_printf *flags, uintmax_t x)
{
	char	*utoa_res;
	int		x_length;

	if (x == 0 && flags->period && !flags->precision)
	{
		while (flags->width--)
			flags->total_length += write(flags->fd, " ", 1);
		return ;
	}
	utoa_res = ft_printf_utoa_base(flags, x, 16);
	x_length = ft_strlen(utoa_res);
	if ((flags->hash && x != 0) || flags->format == 'p')
		x_length += 2;
	if (flags->dash)
		print_hex_right(flags, x, x_length, utoa_res);
	else
		print_hex_left(flags, x, x_length, utoa_res);
	ft_strdel(&utoa_res);
}
