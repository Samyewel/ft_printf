/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:12:56 by swilliam          #+#    #+#             */
/*   Updated: 2022/05/30 14:21:50 by swilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
** ft_putendl_fd:
** - Outputs the string s to the file descriptor fd followed by a ’\n’.
*/

void	ft_putendl_fd(char const *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		ft_putchar_fd(s[i++], fd);
	ft_putchar_fd('\n', fd);
}
