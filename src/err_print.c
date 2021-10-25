/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:44:00 by sherbert          #+#    #+#             */
/*   Updated: 2021/10/25 21:46:32 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int err(char *name)
{
    ft_printf("%s", name);
    if (ft_strncmp(name, "ERR_MALLOC", ft_strlen("ERR_MALLOC")) == 0)
        return (NULL);
    return (ERR);
}