/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 22:48:15 by sherbert          #+#    #+#             */
/*   Updated: 2021/10/22 10:06:33 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_flag	ft_format(const char *str, t_flag flags)
{
	while (!ft_isalpha(*str) && *str && *str != '%')
	{
		if (*str == '-' && flags.dot == 0)
			flags.sign = -1;
		else if (*str == '*' && flags.star == 1)
			flags.star = 3;
		else if (*str == '*' && flags.dot == 0)
			flags.star = 1;
		else if (*str == '*' && flags.dot == 1)
			flags.star = 2;
		else if (*str == '.')
			flags.dot = 1;
		else if (*str == '0' && flags.sign == 1 && !ft_isdigit(*(str - 1)))
			flags.c = '0';
		else if (ft_isdigit(*str) && flags.dot == 0)
			flags.width = (*str - '0') + (flags.width) * 10;
		else if (ft_isdigit(*str) && flags.dot == 1)
			flags.len = (*str - '0') + (flags.len) * 10;
		str++;
	}
	if (flags.sign == -1)
		flags.c = ' ';
	return (flags);
}

t_flag	ft_stars(int i, t_flag flags)
{
	if (flags.star != 2)
	{
		flags.width = i;
		if (flags.width < 0)
		{
			flags.sign = -1;
			flags.width *= -1;
			flags.c = ' ';
		}
		flags.star--;
	}
	else
	{
		flags.len = i;
		flags.star = 0;
		if (flags.len < 0)
			flags.dot = 0;
	}
	return (flags);
}

t_flag	ft_flags_std(const char *str)
{
	t_flag	flags;

	flags.width = 0;
	flags.sign = 1;
	flags.c = ' ';
	flags.dot = 0;
	flags.len = 0;
	flags.star = 0;
	flags = ft_format(str, flags);
	return (flags);
}

void	ft_print_flags(t_flag flags, int len)
{
	int	i;

	i = 0;
	if (flags.width > 0)
	{
		while (i++ < flags.width - len)
			ft_putchar_fd(flags.c, 1);
	}
}
