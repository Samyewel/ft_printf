/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:15:46 by sam               #+#    #+#             */
/*   Updated: 2022/05/30 14:20:44 by swilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** ft_strrchr:
** - Locates the last occurrence of c (converted to a char) in the
**   string pointed to by s.
** - The terminating null character is considered to be part of the
**   string; therefore if c is `\0', the functions locate the terminating `\0'.
*/

char	*ft_strrchr(const char *s, int c)
{
	int	x;
	int	len;

	x = ft_strlen(s);
	len = x;
	while (x >= 0)
	{
		if (s[x] == c)
			return ((char *)s + x);
		x--;
	}
	return (NULL);
}
