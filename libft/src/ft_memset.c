/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:26:08 by swilliam          #+#    #+#             */
/*   Updated: 2022/05/30 14:21:57 by swilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** ft_memset:
** - The memset() function writes len bytes of value c
**	 (converted to an unsigned char) to the string b.
** - Returns first argument.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*edit;
	size_t			x;

	edit = (unsigned char *) b;
	x = 0;
	while (x < len)
		edit[x++] = (unsigned char) c;
	return (b);
}
