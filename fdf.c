/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:48:18 by sherbert          #+#    #+#             */
/*   Updated: 2021/11/09 17:21:09 by sherbert         ###   ########.fr       */
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
    int i;

    i = -1;
    data = malloc(sizeof(t_data));
	if (!data)
		return (err("ERR_MALLOC_DATA"));
	ft_bzero(data, sizeof(t_data));
    data->width = 0;
    data->height = 0;
    data->a = NULL;
    data->pic = ft_calloc(WIDTH * HEIGHT + 1, sizeof(int));
    data->mlx = init_mlx();
}

int				main(int argc, char **argv)
{
	t_data *data;

    if (argc != 2 || valid_input_err(argv[1]))
        return (err("\n"));
	data = init_data(argv[1]);
    data = init_map(data, argv[1]);
    ft_printf("yos");
    // int i;
    // int j;
    // for (i = 0; i < data->width; i++)
    // {
    //     for (j = 0; j < data->height; j++)
    //         ft_printf("%d", data->a[i][j]);
    //     ft_printf("\n");
    // }
    // data->mlx->win = mlx_new_window(data->mlx->mlx, WIDTH, HEIGHT, "FdF");
    // if (!data->mlx->win)
	// 		return (err("ERR_INIT_WIN"));
	// mlx_hook(data->win, 2, 1L << 0, key_pressed, data);
	// mlx_hook(data->win, 3, 1L << 1, key_released, data);
	// mlx_hook(data->win, 17, 1L << 17, event_destroy_window, data);
	// mlx_loop_hook(data->mlx, loop, data);
	// mlx_loop(data->mlx);
	return (0);
}