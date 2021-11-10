/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_in_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:20:30 by sherbert          #+#    #+#             */
/*   Updated: 2021/11/10 10:20:31 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	valid_input_err(char *argv)
{
	int i;

	i = (int)ft_strlen(argv) - 1;
	if (argv[i - 3] != '.' || argv[i - 2] != 'f'
		|| argv[i - 1] != 'd' || argv[i] != 'f')
		return (err("ERR!\n \t\t\t-Not '*.fdf' file"));
	return (SUCCESS);
}

t_data	*free_data(t_data *data)
{
	int x;
	int y;

	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
			data->a[y][x] = 0;
		save_free(&data->a[y]);
	}
	data->width = 0;
	data->height = 0;
	return (data);
}
