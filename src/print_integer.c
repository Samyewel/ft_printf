/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:17:14 by swilliam          #+#    #+#             */
/*   Updated: 2022/07/26 15:18:23 by swilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** integer_prefix:
** - Prints the respective sign for the number given, shortening the width
**   upon printing.
*/

static void	integer_prefix(t_printf *flags, intmax_t d)
{
	if (d >= 0)
		flags->total_length += write(1, "+", 1);
	else if (d < 0)
		flags->total_length += write(1, "-", 1);
	flags->width -= (flags->sign);
}

/*
** integer_left_padding:
** - Prints ' ' or '0' to the left of the converted number.
** - If precision is given, then ' ' will be printed until no more width is
**   available, thus the rest of the string is padded with '0'.
** - If precision is given (using the '.' flag), then the '0' flag is ignored.
** - If no precision is given, then the converted number is padded with '0' if
**   '0' is provided as a flag, otherwise ' ' is printed instead.
*/

static void	integer_left_padding(t_printf *flags, int d_length)
{
	char	padding;

	if (flags->zero_padding && !flags->precision)
		padding = '0';
	else
		padding = ' ';
	if (flags->precision)
	{
		flags->width -= (flags->sign);
		while (flags->width-- > flags->precision)
		{
			if (flags->zero_padding && flags->width != flags->precision)
				flags->total_length += write(flags->fd, "0", 1);
			else
				flags->total_length += write(flags->fd, " ", 1);
		}
	}
	else
	{
		flags->width -= (flags->sign);
		while (flags->width-- > d_length)
			flags->total_length += write(flags->fd, &padding, 1);
	}
}

/*
** print_integer_left:
** - Handles the conversion for when no '-' flag is used.
** - Prints the respective padding to the left of the converted integer,
**   therefore aligning it to the right.
*/

static void	print_integer_left(t_printf *flags, intmax_t d, int d_length
, char *itoa_res)
{
	if (d == 0 && (flags->period || flags->star) && !flags->precision)
	{
		if (flags->plus && flags->width)
			flags->width--;
		while (flags->width--)
			flags->total_length += write(flags->fd, " ", 1);
		if (flags->plus)
			flags->total_length += write(flags->fd, "+", 1);
		return ;
	}
	if (flags->space && !flags->sign && !flags->width)
		flags->total_length += write(flags->fd, " ", 1);
	if (flags->sign && flags->zero_padding)
		integer_prefix(flags, d);
	flags->width += (flags->sign && flags->zero_padding
			&& flags->width && !flags->precision);
	integer_left_padding(flags, d_length);
	if (flags->sign && !flags->zero_padding)
		integer_prefix(flags, d);
	while (d_length++ < flags->precision)
		flags->total_length += write(flags->fd, "0", 1);
	flags->total_length += write(1, itoa_res, ft_strlen(itoa_res));
}

/*
** print_integer_right:
** - Handles the conversion for when the '-' flag is used.
** - Prints the respective padding to the right of the converted integer,
**   therefore aligning it to the left.
*/

static void	print_integer_right(t_printf *flags, intmax_t d, int d_length
, char *itoa_res)
{
	if (d == 0 && !flags->precision)
	{
		if (flags->plus && flags->width)
			flags->width--;
		if (flags->plus)
			flags->total_length += write(flags->fd, "+", 1);
		while (flags->width--)
			flags->total_length += write(flags->fd, " ", 1);
		return ;
	}
	if (flags->space && d >= 0)
		flags->total_length += write(flags->fd, " ", 1);
	if (flags->sign)
		integer_prefix(flags, d);
	while (d_length++ < flags->precision)
		flags->total_length += write(flags->fd, "0", 1);
	flags->total_length += write(1, itoa_res, ft_strlen(itoa_res));
	while (flags->width-- >= d_length)
			flags->total_length += write(flags->fd, " ", 1);
}

/*
** print_integer:
** - Creates a string using the given integer. If the number is negative,
**   the prefixed '-' is removed by converting it to a positive number and
**   printed later during conversion.
** - The "sign" flag is positive if a '+' or a '-' is needed to be printed
**   later during conversion.
** - The length of the created number string is calculated and stored for
**   width and precision printing during conversion.
** - If a '-' flag is used, the conversion will align the string to the left,
**   otherwise it will align to the right.
** - If d is more than the highest possible long long or less than the
**   lowest, then no memory has been allocated and therefore ft_strdel is
**   not called.
*/

void	print_integer(t_printf *flags, intmax_t d)
{
	int		d_length;
	char	*itoa_res;

	if (d < 0)
		itoa_res = ft_printf_signed_itoa(d * -1);
	else
		itoa_res = ft_printf_signed_itoa(d);
	if (!itoa_res)
		ft_printf_error(flags, "Failed to allocate space for 'itoa_res'");
	flags->sign = ((flags->plus && d >= 0) || (d < 0));
	d_length = ft_strlen(itoa_res);
	if (flags->dash)
		print_integer_right(flags, d, d_length, itoa_res);
	else
		print_integer_left(flags, d, d_length, itoa_res);
	if (itoa_res != NULL && ft_strcmp(itoa_res, "9223372036854775808") != 0)
		ft_strdel(&itoa_res);
}
