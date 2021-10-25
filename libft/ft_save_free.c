/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:10:27 by sherbert          #+#    #+#             */
/*   Updated: 2021/10/22 09:19:04 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	save_free(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

void	save_free_int(int **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}
