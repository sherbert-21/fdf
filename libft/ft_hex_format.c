/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 02:00:10 by sherbert          #+#    #+#             */
/*   Updated: 2021/10/22 10:00:33 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_dec_to_hex(unsigned int i)
{
	if (i >= 0 && i <= 9)
		return (i + '0');
	else if (i == 10)
		return ('a');
	else if (i == 11)
		return ('b');
	else if (i == 12)
		return ('c');
	else if (i == 13)
		return ('d');
	else if (i == 14)
		return ('e');
	else
		return ('f');
}

void	ft_hex_format(size_t i, char c)
{
	if (i > 15)
		ft_hex_format(i / 16, c);
	if (c == 'x')
		ft_putchar_fd(ft_dec_to_hex(i % 16), 1);
	else
		ft_putchar_fd((char)ft_toupper(ft_dec_to_hex(i % 16)), 1);
}

int	ft_hex_len(unsigned int i)
{
	int				k;
	unsigned int	hex;

	k = 0;
	hex = i;
	while (hex > 15)
	{
		k++;
		hex /= 16;
	}
	k++;
	return (k);
}

int	ft_point_len(size_t i)
{
	int		k;
	size_t	hex;

	k = 0;
	hex = i;
	while (hex > 15)
	{
		k++;
		hex /= 16;
	}
	k++;
	return (k);
}
