/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:20:24 by sherbert          #+#    #+#             */
/*   Updated: 2021/11/16 13:37:24 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void isometric(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.8);
    *y = (*x + *y) * sin(0.8) - z;
}

void    bresenham(float x0, float y0, float x1, float y1, t_data *data)
{
    float max;
    float x_step;
    float y_step;
    int     z;
    int     z1;

    z = data->a[(int)y0][(int)x0];
    z1 = data->a[(int)y1][(int)x1];
    data->color = 0xffffff;
    if (z)
        data->color = 0xe80c0c;
    max = fabsf(x1 - x0);
    if (max < fabsf(y1 - y0))
        max = fabsf(y1 - y0);
    x_step = (x1 - x0) / max;
    y_step = (y1 - y0) / max;
    while ((int)(x1 - x0) || (int)(y1 - y0))
    {
        mlx_pixel_put(data->mlx->mlx, data->mlx->win, x0, y0, data->color);
        x0 += x_step;
        y0 += y_step;
    }
}

static int check_side(int x, int y, t_data *data)
{
    if ((y == 0 && (x == 0 || x == data->width - 1)) || (y == data->height - 1 && (x == 0 || x == data->width - 1)))
    {
        if (y == 0 && x == 0)
            return (1);
        else if (y == 0 && x == data->width - 1)
            return (2);
        else if (y == data->height - 1 && x == 0)
            return (4);
        else
            return(3);
    }
    else if (y == 0 || x == 0 || x == data->width - 1 || y == data->height - 1)
    {
        if (y == 0)
            return (2);
        else if (x == 0)
            return (1);
        else if (x == data->width - 1)
            return (3);
        else
            return (4);
    }
    else
        return (0);
}

static void check_case(int x, int y, int side, int zoom, t_data *data)
{
    if (side == 0)
        draw_square(x, y, zoom, data);
    else
    {
        if ((y == 0 && (x == 0 || x == data->width - 1)) || (y == data->height - 1 && (x == 0 || x == data->width - 1)))
            draw_angle(x, y, side, zoom, data);
        else
            draw_side(x, y, side, zoom, data);
    }
}

void    draw(t_data *data)
{
    int x;
    int y;
    int x_max;
    int y_max;
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
}