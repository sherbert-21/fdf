/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 02:00:20 by sherbert          #+#    #+#             */
/*   Updated: 2021/10/22 10:07:51 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_flag	ft_flags_length(t_flag flags, int len, size_t i)
{
	if (flags.width < len && flags.width)
		flags.width = len;
	if (flags.len < len && !(flags.len == 0 && i == '0'))
		flags.len = len;
	return (flags);
}

static int	ft_no_dot(size_t i, t_flag flags, int len)
{
	if (flags.width != 0 && flags.sign == 1)
		ft_print_flags(flags, len);
	ft_putstr_fd("0x", 1);
	if (!i)
		i = 0;
	ft_hex_format(i, 'x');
	if (flags.width != 0 && flags.sign == -1)
		ft_print_flags(flags, len);
	if (flags.width >= len)
		return (flags.width);
	return (len);
}

static int	ft_dot(size_t i, t_flag flags, int len)
{
	int	k;

	k = 0;
	flags.c = ' ';
	if (flags.width != 0 && flags.sign == 1)
		ft_print_flags(flags, flags.len);
	ft_putstr_fd("0x", 1);
	while (k++ < flags.len - len)
		ft_putchar_fd('0', 1);
	if (!(flags.len == 0 && i == '0'))
		ft_hex_format(i, 'x');
	if (flags.width != 0 && flags.sign == -1)
		ft_print_flags(flags, flags.len);
	if (flags.width >= flags.len)
		return (flags.width);
	return (flags.len);
}

int	ft_print_point(size_t i, t_flag flags)
{
	int	len;

	len = ft_point_len(i) + 2;
	flags = ft_flags_length(flags, len, i);
	if (flags.dot == 0)
		return (ft_no_dot(i, flags, len));
	else
		return (ft_dot(i, flags, len));
}
