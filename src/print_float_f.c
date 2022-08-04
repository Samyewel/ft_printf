/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:40:29 by swilliam          #+#    #+#             */
/*   Updated: 2022/07/26 15:45:58 by swilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print_float_f_left:
** - Handles the conversion for when no '-' flag is used.
** - Handles characters being printed to the left of the given input, therefore
**   aligning it to the right.
*/

static void	print_float_f_left(t_printf *flags, int f_length, char *f_string)
{
	if (flags->zero_padding)
	{
		if (flags->sign)
			flags->total_length += write(flags->fd, "-", 1);
		if (!flags->sign && flags->space)
			flags->total_length += write(flags->fd, " ", 1);
		flags->width--;
	}
	if (!flags->zero_padding && flags->sign)
		flags->width--;
	while (flags->width-- > f_length)
	{
		if (flags->zero_padding)
			flags->total_length += write(flags->fd, "0", 1);
		else
			flags->total_length += write(flags->fd, " ", 1);
	}
	if (!flags->zero_padding && flags->sign)
		flags->total_length += write(flags->fd, "-", 1);
	flags->total_length += write(flags->fd, f_string, f_length);
}

/*
** print_float_f_right:
** - Handles the conversion for when the '-' flag is used.
** - Handles characters being printed to the right of the given input, therefore
**   aligning it to the left.
*/

static void	print_float_f_right(t_printf *flags, int f_length, char *f_string)
{
	if (flags->sign)
	{
		flags->total_length += write(flags->fd, "-", 1);
		flags->width--;
	}
	else if (!flags->sign && flags->space)
	{
		flags->total_length += write(flags->fd, " ", 1);
		flags->width--;
	}
	flags->total_length += write(flags->fd, f_string, f_length);
	while (flags->width-- > f_length)
		flags->total_length += write(flags->fd, " ", 1);
}

/*
** print_f_float:
** - Uses float_f_rounding to calculate and create a string containing the float
**   converted into an integer, then into characters, with its decimal point
**   manually inserted.
** - If float is 0.0, we need to manually add the remaining five trailing 0s.
** - If a '-' flag is used, the conversion will align the string to the left,
**   otherwise it will align to the right.
*/

void	print_float_f(t_printf *flags, double f)
{
	char	*f_string;
	char	*temp;
	int		f_length;

	f_string = float_f_rounding(flags, f);
	if (f_string == NULL)
		return ;
	if (ft_strcmp(f_string, "0.0") == 0)
	{
		temp = ft_strdup(f_string);
		ft_strdel(&f_string);
		f_string = ft_strjoin(temp, "00000");
		ft_strdel(&temp);
	}
	if (f_string == NULL)
		return ;
	f_length = ft_strlen(f_string);
	if (flags->dash)
		print_float_f_right(flags, f_length, f_string);
	else
		print_float_f_left(flags, f_length, f_string);
	if (f_string != NULL)
		ft_strdel(&f_string);
}
