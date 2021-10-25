/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 09:49:25 by sherbert          #+#    #+#             */
/*   Updated: 2021/10/22 09:51:13 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*s_init_one(const char *s)
{
	if (*(s - 1) != '*' && *s == '%')
		s++;
	return (s);
}

const char	*s_init_two(const char *s)
{
	if (*s == '.' && *(s - 1) == '*')
		s++;
	return (s);
}	

t_flag	flags_init(t_flag flags, const char *s)
{
	if (*(s - 1) == '%')
		return (ft_flags_std(s));
	return (flags);
}
