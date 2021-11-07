/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:50:09 by sherbert          #+#    #+#             */
/*   Updated: 2021/11/01 22:56:47 by sherbert         ###   ########.fr       */
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

# define ERR 0
# define SUCCESS 1
# define NEXT 2

typedef struct s_mlx_init
{
    void    *mlx;
    void    *win;
    void    *img;
    int     bpp;
    int     endian;
    int     sl;
}              t_mlx_init;

typedef struct s_data
{
    int         **a;
    int         size;
    int         width;
    int         *pic;
    t_mlx_init  *mlx;
}              t_data;

int   check_map_size(char *argv);
int   check_map_width(char *argv);
int     *fill_data(char *line, t_data *data);
t_data    *init_map(char **argv, t_data *data);
int map_check(char *argv);
int err(char *name);

#endif