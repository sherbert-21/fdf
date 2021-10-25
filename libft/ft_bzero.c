/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 17:05:33 by sherbert          #+#    #+#             */
/*   Updated: 2021/10/21 19:49:12 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < len)
	{
		*str = '\0';
		i++;
		str++;
	}
}

void	ft_bzero_int(void *s, size_t len)
{
	size_t	i;
	int		*a;

	i = 0;
	a = (int *)s;
	while (i < len)
	{
		*a = 0;
		i++;
		a++;
	}
}
