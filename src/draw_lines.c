/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:44:00 by sherbert          #+#    #+#             */
/*   Updated: 2021/11/17 17:50:51 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void get_z(int *z, int x, int y, t_data *data)
{
    *z = 0;
    if ((x / 30) < data->width && (y / 30) < data->height)
        *z = data->a[y / 30][x / 30];
}

static void isometric(float *x, float *y, int z, t_data *data)
{
    if (data->angle)
    {
        *x = (*x - *y) * cos(data->angle);
        *y = (*x + *y) * sin(data->angle) - z;
    }
    *x += data->shift_x;
    *y += data->shift_y;
}

void    bresenham(float x0, float y0, float x1, float y1, t_data *data)
{
    float max;
    float x_step;
    float y_step;
    int     z;
    int     z1;

    get_z(&z, (int) x0, (int) y0, data);
    get_z(&z1, (int) x1, (int) y1, data);
    if (z || z1)
        data->color = 0xe80c0c;
    isometric(&x0, &y0, z, data);
    isometric(&x1, &y1, z1, data);
    max = fabsf(x1 - x0);
    if (max < fabsf(y1 - y0))
        max = fabsf(y1 - y0);
    x_step = (x1 - x0) / max;
    y_step = (y1 - y0) / max;
    while ((int)(x1 - x0) || (int)(y1 - y0))
    {
        // data->img->canvas[(int)y0 * WIDTH + (int)x0] = data->color;
        mlx_pixel_put(data->mlx->mlx, data->mlx->win, x0, y0, data->color);
        x0 += x_step;
        y0 += y_step;
    }
}