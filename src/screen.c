/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:20:24 by sherbert          #+#    #+#             */
/*   Updated: 2021/11/17 17:49:17 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int check_side(int x, int y, t_data *data)
{
    if (y == 0 && x == 0)
        return (1);
    else if (y == 0 && x == data->width - 1)
        return (2);
    else if (y == data->height - 1 && x == 0)
        return (4);
    else if (y == data->height - 1 && x == data->width - 1)
        return(3);
    else if (y == 0)
        return (2);
    else if (x == 0)
        return (1);
    else if (x == data->width - 1)
        return (3);
    else if (y == data->height - 1)
            return (4);
    else
        return (0);
}

static void check_case(int x, int y, int side, int zoom, t_data *data)
{
    data->color = 0xffffff;
    if (side == 0)
        draw_square(x, y, zoom, data);
    else
    {
        if ((y == 0 && x == 0) ||
            (y == 0 && x == data->width - 1) ||
            (y == data->height - 1 && x == 0) ||
            (y == data->height - 1 && x == data->width - 1))
            draw_angle(x, y, side, zoom, data);
        else
            draw_side(x, y, side, zoom, data);
    }
}

void    draw(t_data *data)
{
    int x;
    int y;
    int side;
    
    y = -1;
    while (++y < data->height)
    {
        x = -1;
        while (++x < data->width)
        {
            side = check_side(x, y, data);
            check_case(x, y, side, data->zoom, data);
        }
    }
    // mlx_pixel_put(data->mlx->mlx, data->mlx->win, 400, 400, 0x00ff00);
}