/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 19:54:30 by sherbert          #+#    #+#             */
/*   Updated: 2021/10/22 10:00:41 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;

	str = (char *)malloc(nmemb * size);
	if (!str)
		return (NULL);
	ft_bzero(str, nmemb * size);
	return (str);
}

void	*ft_calloc_int(size_t nmemb)
{
	int	*a;

	a = (int *)malloc(nmemb * sizeof(int));
	if (!a)
		return (NULL);
	ft_bzero_int(a, nmemb * sizeof(int));
	return (a);
}
