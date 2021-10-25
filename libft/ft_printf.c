/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:03:58 by sherbert          #+#    #+#             */
/*   Updated: 2021/10/22 09:58:01 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ok(char c)
{
	return ((int)ft_strchr("cCsSpPdDiIuUxX%*", c) || ft_isdigit(c));
}

static int	ft_read(char c)
{
	return ((int)ft_strchr("cCsSpPdDiIuUxX%", c));
}

static int	ft_conv_case(const char str, va_list list, t_flag flags)
{
	int	i;

	i = 0;
	if (str == '%')
		i = ft_print_char('%', flags);
	else if (str == 'i' || str == 'd' || str == 'D' || str == 'I')
		i = ft_print_nbr(va_arg(list, int), flags);
	else if (str == 'c' || str == 'C')
		i = ft_print_char((char)va_arg(list, int), flags);
	else if (str == 's' || str == 'S')
		i = ft_print_str(va_arg(list, char *), flags);
	else if (str == 'U' || str == 'u')
		i = ft_print_unsign(va_arg(list, unsigned int), flags);
	else if (str == 'x' || str == 'X')
		i = ft_print_hex(va_arg(list, unsigned int), flags, str);
	else if (str == 'p' || str == 'P')
		i = ft_print_point(va_arg(list, size_t), flags);
	return (i);
}

static int	ft_print(const char *s, va_list list, t_flag flags, int i)
{
	while (*s != '\0')
	{
		if (*s == '%')
		{
			while (ft_ok(*s) && !(*(s - 1) == '%' && *(s - 2) == '%'
					&& *s != '%') && *s && !(ft_read(*(s - 1)) && *s != '%'))
			{
				s = s_init_one(s);
				flags = flags_init(flags, s);
				while (!(ft_read(*s) || *s == '*'))
					s++;
				if (flags.star != 0 && *s++)
					flags = ft_stars(va_arg(list, int), flags);
				else
					i += ft_conv_case(*s++, list, flags);
				s = s_init_two(s);
			}
		}
		while (*s != '\0' && *s != '%')
		{
			ft_putchar_fd(*s++, 1);
			i++;
		}
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	t_flag		flags;
	int			i;

	i = 0;
	flags = ft_flags_std(str);
	va_start(arg, str);
	if (*str)
		i = ft_print(str, arg, flags, i);
	va_end(arg);
	return (i);
}
