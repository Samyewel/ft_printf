/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:17:07 by swilliam          #+#    #+#             */
/*   Updated: 2021/12/12 17:17:33 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_isprint:
** - Checks if the input integer is an ascii character that
**	 is visible on a standard output.
*/

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
