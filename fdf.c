/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:48:18 by sherbert          #+#    #+#             */
/*   Updated: 2021/10/25 21:54:14 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"

static t_mlx_init   *init_mlx(void)
{
    t_mlx_init  *mlx;
    
    mlx = malloc(sizeof(t_mlx_init));
    if (!mlx)
		return (err("ERR_MALLOC_MLX"));
    ft_bzero(mlx, sizeof(t_mlx_init));
    mlx = mlx_init();
    if (!mlx)
        return (err("ERR_MALLOC_MLX"));
    return (mlx);
}

static t_data   *init_data(char *argv)
{
    t_data *data;

    data = malloc(sizeof(t_data));
	if (!data)
		return (err("ERR_MALLOC_DATA"));
	ft_bzero(data, sizeof(t_data));
    data->size = check_map_size(argv);
    data->a = ft_calloc(data->size + 1, sizeof(int));
    if (!data->a)
        return (err("ERR_MALLOC_MAP"));
    data->pic = ft_calloc(WIDTH * HEIGHT + 1, sizeof(int));
    data->mlx = init_mlx;
    return (data);
}

int				main(int argc, char **argv)
{
	t_data *data;

    if (argc < 2 || !map_check(argv[1]))
        return (err("ERR_IN_MAP!"));
	data = init_data(argv[1]);
    init_map(data, argv[1]);
    data->mlx->win = mlx_new_window(data->mlx->mlx, WIDTH, HEIGHT, "FdF");
    if (!data->mlx->win)
			return (err("ERR_INIT_WIN"));
	return (0);
}