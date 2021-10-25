/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 20:01:32 by sherbert          #+#    #+#             */
/*   Updated: 2021/10/22 10:08:12 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_no_dot(char *s, t_flag flags, int len)
{
	if (flags.width != 0 && flags.sign == 1)
		ft_print_flags(flags, len);
	ft_putstr_fd(s, 1);
	if (flags.width != 0 && flags.sign == -1)
		ft_print_flags(flags, len);
	if (flags.width >= len)
		return (flags.width);
	return (len);
}

static int	ft_dot(char *s, t_flag flags, int len)
{
	char	*str;

	if (len >= flags.len && flags.len >= 0)
		len = flags.len;
	if (flags.width != 0 && flags.sign == 1)
		ft_print_flags(flags, len);
	ft_putstr_fd(str = ft_substr(s, 0, len), 1);
	if (flags.width != 0 && flags.sign == -1)
		ft_print_flags(flags, len);
	free(str);
	if (flags.width >= len)
		return (flags.width);
	return (len);
}

int	ft_print_str(char *s, t_flag flags)
{
	int	len;

	len = 0;
	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (flags.dot == 0)
		return (ft_no_dot(s, flags, len));
	else
		return (ft_dot(s, flags, len));
}
