/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float_f_utilities.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:23:08 by swilliam          #+#    #+#             */
/*   Updated: 2022/07/26 15:23:40 by swilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** float_f_locate_point:
** - Used to locate the decimal point within the float.
*/

int	float_f_locate_point(t_printf *flags, intmax_t f_int)
{
	char	*temp;
	int		i;
	int		point;
	int		point_location;

	temp = ft_printf_signed_itoa(f_int);
	i = ft_strlen(temp);
	while (i-- > 1)
	{
		if (flags->precision_specified)
			if (i == flags->precision)
				point = i;
		if (!flags->precision_specified)
			if (i == 6)
				point = i;
	}
	point_location = ft_strlen(temp) - point;
	ft_strdel(&temp);
	return (point_location);
}

/*
** float_f_itodstr:
** - Once the double has been converted to a whole number, it is sent here
**   to be converted into a string for later printing.
** - The location of the decimal place is calculated and manually placed.
** - If the double is a fraction of 0, a zero is manually placed, as it is
**   removed when it becomes a whole number.
*/

char	*float_f_itodstr(t_printf *flags, double f, intmax_t f_int)
{
	char	*temp;
	char	*string;
	int		i;
	int		j;
	int		point_location;

	temp = ft_printf_signed_itoa(f_int);
	string = ft_strnew(ft_strlen(temp) + 1 + (f > -1 && f < 1));
	point_location = float_f_locate_point(flags, f_int);
	i = 0;
	j = 0;
	if (f > -1.0 && f < 1.0)
	{
		string[j++] = '0';
		string[j++] = '.';
	}
	while (temp[i])
	{
		string[j++] = temp[i++];
		if (i == point_location && !(f > -1.0 && f < 1.0))
			string[j++] = '.';
	}
	if (temp != NULL)
		ft_strdel(&temp);
	return (string);
}

/*
** float_f_rounding:
** - Converts a given double into a whole number. The precision provided
**   is later used to calculate the location of the decimal point.
** - Removes a '-' for negative numbers, and later manually placed during
**   printing.
*/

char	*float_f_rounding(t_printf *flags, double f)
{
	intmax_t	i;
	intmax_t	f_int;
	double		f_dbl;
	int			precision_count;

	i = 0;
	f_dbl = f;
	flags->sign = (1 / f < 0.0);
	if (flags->precision_specified)
		precision_count = flags->precision;
	else
		precision_count = 6;
	while (i++ != precision_count)
		f_dbl *= 10;
	if (f < 0.0)
		f_int = (intmax_t)(f_dbl - 0.5) * -1;
	else
		f_int = (intmax_t)(f_dbl + 0.5);
	return (float_f_itodstr(flags, f, f_int));
}
