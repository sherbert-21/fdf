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

void    draw_angle(int x, int y, int side, int zoom, t_data *data)
{
    if (side == 1 || side == 2)
        bresenham(x * zoom, y * zoom, (x + 1) * zoom, y * zoom, data);
    else
        bresenham(x * zoom, (y + 1) * zoom, (x + 1) * zoom, (y + 1) * zoom, data);
    if (side == 1 ||side == 4)
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