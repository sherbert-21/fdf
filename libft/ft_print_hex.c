/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:10:11 by sherbert          #+#    #+#             */
/*   Updated: 2021/10/22 10:06:55 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_flag	ft_flags_length(t_flag flags, int len, unsigned int i)
{
	if (flags.width < len && flags.width)
		flags.width = len;
	if (flags.len < len && !(flags.len == 0 && i == 0))
		flags.len = len;
	return (flags);
}

static int	ft_no_dot(unsigned int i, t_flag flags, int len, char c)
{
	if (flags.width != 0 && flags.sign == 1)
		ft_print_flags(flags, len);
	ft_hex_format(i, c);
	if (flags.width != 0 && flags.sign == -1)
		ft_print_flags(flags, len);
	if (flags.width >= len)
		return (flags.width);
	return (len);
}

static int	ft_dot(unsigned int i, t_flag flags, int len, char c)
{
	int	k;

	k = 0;
	flags.c = ' ';
	if (flags.width != 0 && flags.sign == 1)
		ft_print_flags(flags, flags.len);
	while (k++ < flags.len - len)
		ft_putchar_fd('0', 1);
	if (!(flags.len == 0 && i == 0))
		ft_hex_format(i, c);
	if (flags.width != 0 && flags.sign == -1)
		ft_print_flags(flags, flags.len);
	if (flags.width >= flags.len)
		return (flags.width);
	return (flags.len);
}

int	ft_print_hex(unsigned int i, t_flag flags, char c)
{
	int	len;

	len = ft_hex_len(i);
	flags = ft_flags_length(flags, len, i);
	if (flags.dot == 0)
		return (ft_no_dot(i, flags, len, c));
	else
		return (ft_dot(i, flags, len, c));
}
