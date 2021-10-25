/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 03:39:37 by sherbert          #+#    #+#             */
/*   Updated: 2021/10/22 10:09:04 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_flag	ft_flags_length(t_flag flags, int len, char *n)
{
	if (flags.width < len && flags.width)
		flags.width = len;
	if (flags.len < len && !(flags.len == 0 && *n == '0'))
		flags.len = len;
	return (flags);
}

static int	ft_no_dot(char *n, t_flag flags, int len)
{
	if (flags.width != 0 && flags.sign == 1)
		ft_print_flags(flags, len);
	ft_putstr_fd(n, 1);
	if (flags.width != 0 && flags.sign == -1)
		ft_print_flags(flags, len);
	if (flags.width >= len)
		return (flags.width);
	return (len);
}

static int	ft_dot(char *n, t_flag flags, int len)
{
	int	k;

	k = 0;
	flags.c = ' ';
	if (flags.width != 0 && flags.sign == 1)
		ft_print_flags(flags, flags.len);
	while (k++ < flags.len - len)
		ft_putchar_fd('0', 1);
	if (!(flags.len == 0 && *n == '0'))
		ft_putstr_fd(n, 1);
	if (flags.width != 0 && flags.sign == -1)
		ft_print_flags(flags, flags.len);
	if (flags.width >= flags.len)
		return (flags.width);
	return (flags.len);
}

int	ft_print_unsign(unsigned int i, t_flag flags)
{
	int		len;
	char	*nbr;

	nbr = ft_utoa(i);
	len = ft_strlen(nbr);
	flags = ft_flags_length(flags, len, nbr);
	if (flags.dot == 0)
		len = ft_no_dot(nbr, flags, len);
	else
		len = ft_dot(nbr, flags, len);
	free(nbr);
	return (len);
}
