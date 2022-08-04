/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:13:02 by swilliam          #+#    #+#             */
/*   Updated: 2022/05/30 14:21:30 by swilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** ft_strclr:
** - Sets every character of the string to the value ’\0’.
*/

void	ft_strclr(char *s)
{
	int	i;
	int	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		s[i] = '\0';
		i++;
	}
}
