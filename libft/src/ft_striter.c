/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:05:12 by swilliam          #+#    #+#             */
/*   Updated: 2022/05/30 14:21:17 by swilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** ft_striter:
** - Applies the function f to each character of the string passed as argument.
** - Each character is passed by address to f to be modified if necessary.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	int	x;

	x = 0;
	if (!s || !f)
		return ;
	while (s[x])
		f(&s[x++]);
}
