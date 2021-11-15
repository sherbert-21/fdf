/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:48:18 by sherbert          #+#    #+#             */
/*   Updated: 2021/11/14 19:48:44 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"

static t_pic        *init_pic(void)
{
    t_pic   *pic;

    pic = malloc(sizeof(t_pic));
    if (!pic)
		return (err("ERR_MALLOC_PIC"));
    ft_bzero(pic, sizeof(t_pic));
    pic->x = 0;
    pic->y = 0;
    pic->x_step = 0;
    pic->y_step = 0;
    pic->dir_y = 0;
    return (pic);
}

static t_mlx_init   *init_mlx(void)
{
    t_mlx_init  *mlx;
    
    mlx = malloc(sizeof(t_mlx_init));
    if (!mlx)
		return (err("ERR_MALLOC_MLX"));
    ft_bzero(mlx, sizeof(t_mlx_init));
    mlx = mlx_init();
    mlx->data = (int *)mlx_get_data_addr(mlx->img, &mlx->bpp,
				&mlx->sl, &mlx->endian);
    if (!mlx)
        return (err("ERR_MALLOC_MLX"));
    return (mlx);
}

static t_data   *init_data()
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
    data->zoom = 30;
    data->a = NULL;
    data->pic = ft_calloc(WIDTH * HEIGHT + 1, sizeof(int));
    data->mlx = init_mlx();
    data->screen = init_pic();
    return (data);
}

int				main(int argc, char **argv)
{
	t_data *data;

    if (argc != 2 || valid_input_err(argv[1]))
        return (err("\n"));
	data = init_data();
    data = init_map(argv[1], data);
    data->mlx->win = mlx_new_window(data->mlx->mlx, WIDTH, HEIGHT, "FdF");
    if (!data->mlx->win)
			return (err("ERR_INIT_WIN"));
    draw(data);
	mlx_hook(data->mlx->win, 2, 1L << 0, key_pressed, data);
	// mlx_hook(data->win, 3, 1L << 1, key_released, data);
	mlx_hook(data->mlx->win, 17, 1L << 17, event_destroy_window, data);
	// mlx_loop_hook(data->mlx, loop, data);
	mlx_loop(data->mlx);
	return (0);
}