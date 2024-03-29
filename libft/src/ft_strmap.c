/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:13:12 by swilliam          #+#    #+#             */
/*   Updated: 2022/05/30 14:21:05 by swilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** ft_strmap:
** - Applies the function f to each character of the string given as argument
**   to create a “fresh” new string (with malloc(3)) resulting from the
**   successive applications of f.
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		x;
	int		len;
	char	*newstr;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	newstr = ft_strnew(len);
	if (!(newstr))
		return (NULL);
	x = 0;
	while (x < len)
	{
		newstr[x] = f(s[x]);
		x++;
	}
	return (newstr);
}
