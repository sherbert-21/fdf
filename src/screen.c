/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:20:24 by sherbert          #+#    #+#             */
/*   Updated: 2021/11/14 19:54:05 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int check_side(int x, int y, t_data *data)
{

}

static void check_case(int x, int y, int side, int zoom, t_data *data)
{
    
}

void    draw(t_data *data)
{
    int x;
    int y;
    int x_max;
    int y_max;
    int side;

    y = -1;
    y_max = data->height - 2;
    x_max = data->width - 2;
    while (++y < data->height)
    {
        x = -1;
        while (++x < data->width)
        {
            if (y == 0 || x == 0 || y == y_max || x == x_max)
                side = check_side(x, y, data);
            check_case(x, y, side, data->zoom, data);
        }
    }
}