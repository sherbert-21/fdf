/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:50:09 by sherbert          #+#    #+#             */
/*   Updated: 2021/11/14 19:52:38 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <math.h>

# define ESC 53
# define A 0
# define S 1
# define D 2
# define W 13
# define _LEFT 123
# define _RIGHT 124
# define _UP 126
# define _DOWN 125

# define WIDTH 800
# define HEIGHT 800

# define ERR 1
# define SUCCESS 0
# define NEXT 2

typedef struct s_mlx_init
{
    void    *mlx;
    void    *win;
    void    *img;
    int     bpp;
    int     endian;
    int     sl;
    int     *data;
}              t_mlx_init;

typedef struct pic
{
    float   x_step;
    float   y_step;
    float   x;
    float   y;
    float   dir_y;
}           t_pic;

typedef struct s_data
{
    int         **a;
    int         width;
    int         height;
    int         zoom;
    int         *pic;
    t_mlx_init  *mlx;
    t_pic       *screen;
}              t_data;

int             check_map_height(char *argv);
int             check_map_width(char *argv);
int             *fill_data(char *line, t_data *data);
t_data          *init_map(char *argv, t_data *data);
int             valid_input_err(char *argv);
int             err(char *name);
t_data          *free_data(t_data *data);
int		        event_destroy_window(void *param);

void            bresenham(float x0, float x1, float y0, float y1, t_data *data);
void    draw_angle(int x, int y, int side, int zoom, t_data *data);
void    draw_square(int x, int y, int zoom, t_data *data);
void    draw_side(int x, int y, int side, int zoom, t_data *data);
void    draw(t_data *data);

int		key_pressed(int key, void *param);

#endif