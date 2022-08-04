/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:33:04 by swilliam          #+#    #+#             */
/*   Updated: 2022/05/30 14:20:41 by swilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_strrev(char *str)
{
	char	rev[100];
	int		i;
	int		length;

	i = 0;
	length = ft_strlen(str);
	while (i < length)
	{
		rev[i] = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = rev[i];
		i++;
	}
	str[i] = '\0';
}
