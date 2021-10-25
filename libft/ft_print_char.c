/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 03:32:58 by sherbert          #+#    #+#             */
/*   Updated: 2021/10/22 10:06:02 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(char c, t_flag flags)
{
	if (flags.width != 0 && flags.sign == 1)
		ft_print_flags(flags, 1);
	ft_putchar_fd(c, 1);
	if (flags.width != 0 && flags.sign == -1)
		ft_print_flags(flags, 1);
	if (flags.width)
		return (flags.width);
	return (1);
}
