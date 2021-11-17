/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:48:18 by sherbert          #+#    #+#             */
/*   Updated: 2021/11/17 17:50:07 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"

// static t_img        *init_img(void)
// {
//     t_img *img;

//     img = malloc(sizeof(t_img));
//     if (!img)
//         return(err("ERR_MALLOC_IMG"));
//     img->img_h = 0;
//     img->img_w = 0;
//     img->canvas = ft_calloc(WIDTH * HEIGHT + 1, sizeof(int));
//     return (img);
// }

static t_keybuffer  *init_keys(void)
{
    t_keybuffer *key;

    key = malloc(sizeof(t_keybuffer));
	if (!key)
		return (err("ERR_MALLOC_KEY"));
	ft_bzero(key, sizeof(t_keybuffer));
    key->down = 0;
    key->left = 0;
    key->right = 0;
    key->up = 0;
    key->turn_down = 0;
    key->turn_up = 0;
    key->turn_right = 0;
    key->turn_left = 0;
    return (key);
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
    data->color = 0xffffff;
    data->a = NULL;
    data->zoom = 30;
    data->angle = 0.8;
    data->shift_x = WIDTH / 2;
    data->shift_y = HEIGHT / 2;
    data->mlx = init_mlx();
    // data->key = init_keys();
    // data->img = init_img();
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
	// mlx_hook(data->mlx->win, 3, 1L << 1, key_released, data);
	mlx_hook(data->mlx->win, 17, 1L << 17, event_destroy_window, data);
	// mlx_loop_hook(data->mlx->mlx, loop, data);
    draw(data);
	mlx_loop(data->mlx->mlx);
	return (0);
}