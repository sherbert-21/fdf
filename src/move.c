#include "../include/fdf.h"

void left(t_data *data)
{
    if (data->shift_x > 0)
        data->shift_x--;
    else
        data->shift_x = 0;
}

void right(t_data *data)
{
    if (data->shift_x < WIDTH)
        data->shift_x++;
    else
        data->shift_x = WIDTH;
}

void down(t_data *data)
{
    if (data->shift_y < HEIGHT)
        data->shift_y--;
    else
        data->shift_y = HEIGHT;
}

void up(t_data *data)
{
    if (data->shift_y < HEIGHT)
        data->shift_y++;
    else
        data->shift_y = HEIGHT;
}
