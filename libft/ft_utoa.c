/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 07:52:17 by sherbert          #+#    #+#             */
/*   Updated: 2021/10/21 20:06:17 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(unsigned int nb)
{
	int		i;

	i = 0;
	while (nb >= 10)
	{
		i++;
		nb = nb / 10;
	}
	i++;
	return (i);
}

char	*ft_utoa(unsigned int n)
{
	unsigned int	i;
	char			*str;

	i = ft_len(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (n == 0)
		str[--i] = '0';
	while (n)
	{
		i--;
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
