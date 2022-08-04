/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:24:47 by swilliam          #+#    #+#             */
/*   Updated: 2022/05/30 14:22:54 by swilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** ft_bzero:
** - Writes n zeroed bytes to the string s.  If n is zero, bzero() does nothing.
*/

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*edit;
	size_t			x;

	if (n > 0)
	{
		edit = (unsigned char *) s;
		x = 0;
		while (x < n)
		{
			edit[x] = 0;
			x++;
		}
	}
}
