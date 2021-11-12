/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:20:24 by sherbert          #+#    #+#             */
/*   Updated: 2021/11/12 16:12:16 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void    bresenham(float x0, float x1, float y0, float y1, t_data *data)
{
    int error;
    int deltaerr;

    data->screen->x_step = abs(x1 - x0);
    data->screen->y_step = abs(y1 - y0);
    data->screen->y = y0;
    data->screen->dir_y = y1 - y0;
    if (data->screen->dir_y > 0)
        data->screen->dir_y = 1;
    if (data->screen->dir_y < 0)
        data->screen->dir_y = -1;
    data->screen->x = x0 - 1;
    deltaerr = data->screen->y_step + 1;
    error = 0;
    while (++data->screen->x < x1)
    {
        mlx_pixel_put(data->mlx->mlx, data->mlx->win, data->screen->x, data->screen->y, 0xffffff);
        error += deltaerr;
        if (error >= (data->screen->x_step + 1))
        {
            data->screen->y += data->screen->dir_y;
            error -= (data->screen->x_step + 1);
        }
    }
    // int max;

    // data->screen->x_step = x1 - x0;
    // data->screen->y_step = y1 - y0;
    // max = data->screen->y_step;
    // if (data->screen->x_step > data->screen->y_step)
    //     max = data->screen->x_step;
    // data->screen->x_step /= max;
    // data->screen->y_step /= max;
    // while ((int)(x0 - x1) || (int)(y0 - y1))
    // {
    //     mlx_pixel_put(data->mlx->mlx, data->mlx->win, x0, y1, 0xffffff);
    //     x0 += data->screen->x_step;
    //     y0 += data->screen->y_step;
    // }
}