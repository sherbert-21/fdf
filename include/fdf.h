/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:50:09 by sherbert          #+#    #+#             */
/*   Updated: 2021/10/25 21:50:15 by sherbert         ###   ########.fr       */
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
    int         *pic;
    t_mlx_init  *mlx;
}              t_data;

int   check_map_size(char *argv);

#endif