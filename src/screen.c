/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:20:24 by sherbert          #+#    #+#             */
/*   Updated: 2021/11/12 18:16:09 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void    bresenham(float x0, float y0, float x1, float y1, t_data *data)
{
    float max;
    float x_step;
    float y_step;

    max = fabsf(x1 - x0);
    if (max < fabsf(y1 - y0))
        max = fabsf(y1 - y0);
    x_step = (x1 - x0) / max;
    y_step = (y1 - y0) / max;
    while ((int)(x1 - x0) || (int)(y1 - y0))
    {
        mlx_pixel_put(data->mlx->mlx, data->mlx->win, x0, y0, 0xffffff);
        x0 += x_step;
        y0 += y_step;
    }
}

void    draw(t_data *data)
{
    int x;
    int y;
    int zoom;

    y = -1;
    zoom = 30;
    while (++y <= data->height)
    {
        x = -1;
        while (++x <= data->width)
        {
            bresenham(x * zoom, y * zoom, (x + 1) * zoom, y * zoom, data);
            bresenham(x * zoom, y * zoom, x * zoom, (y + 1) * zoom, data);
        }
    }
}