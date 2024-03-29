/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_utilities.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:45:41 by sam               #+#    #+#             */
/*   Updated: 2022/08/03 15:15:43 by swilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_printf_unsigned_number_length:
** - Calculates the length of an unsigned number.
*/

int	ft_printf_unsigned_number_length(uintmax_t n, int base)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

/*
** ft_printf_utoa:
** - Converts an unsigned number to an ascii value.
*/

char	*ft_printf_utoa_base(t_printf *flags, uintmax_t input, int base)
{
	char		*radix;
	char		*res;
	int			len;

	len = ft_printf_unsigned_number_length(input, base);
	res = ft_strnew(len);
	if (!res)
		return (0);
	if (flags->format == 'X')
		radix = ft_strdup("0123456789ABCDEF");
	else
		radix = ft_strdup("0123456789abcdef");
	while (len-- > 0)
	{
		res[len] = radix[input % base];
		input /= base;
	}
	ft_strdel(&radix);
	return (res);
}
