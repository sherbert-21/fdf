/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_net.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:19:15 by sherbert          #+#    #+#             */
/*   Updated: 2021/11/16 13:19:16 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void    draw_angle(int x, int y, int side, int zoom, t_data *data)
{
    if (side == 1 || side == 2)
        bresenham(x * zoom, y * zoom, (x + 1) * zoom, y * zoom, data);
    else
        bresenham(x * zoom, (y + 1) * zoom, (x + 1) * zoom, (y + 1) * zoom, data);
    if (side == 1 || side == 4)
        bresenham(x * zoom, y * zoom, x * zoom, (y + 1) * zoom, data);
    else
        bresenham((x + 1) * zoom, y * zoom, (x + 1) * zoom, (y + 1) * zoom, data);
}

void    draw_square(int x, int y, int zoom, t_data *data)
{
    bresenham(x * zoom, y * zoom, (x + 1) * zoom, y * zoom, data);
    bresenham(x * zoom, y * zoom, x * zoom, (y + 1) * zoom, data);
    bresenham((x + 1) * zoom, y * zoom, (x + 1) * zoom, (y + 1) * zoom, data);
    bresenham(x * zoom, (y + 1) * zoom, (x + 1) * zoom, (y + 1) * zoom, data);
}

void    draw_side(int x, int y, int side, int zoom, t_data *data)
{
    if (side == 1 || side == 3)
    {
        bresenham(x * zoom, y * zoom, (x + 1) * zoom, y * zoom, data);
        bresenham(x * zoom, (y + 1) * zoom, (x + 1) * zoom, (y + 1) * zoom, data);
    }
    else
    {
        bresenham(x * zoom, y * zoom, x * zoom, (y + 1) * zoom, data);
        bresenham((x + 1) * zoom, y * zoom, (x + 1) * zoom, (y + 1) * zoom, data);
    }
    if (side == 1)
        bresenham(x * zoom, y * zoom, x * zoom, (y + 1) * zoom, data);
    else if (side == 2)
        bresenham(x * zoom, y * zoom, (x + 1) * zoom, y * zoom, data);
    else if (side == 3)
        bresenham((x + 1) * zoom, y * zoom, (x + 1) * zoom, (y + 1) * zoom, data);
    else
        bresenham(x * zoom, (y + 1) * zoom, (x + 1) * zoom, (y + 1) * zoom, data);
}