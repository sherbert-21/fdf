/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:01:58 by sherbert          #+#    #+#             */
/*   Updated: 2021/11/05 14:18:42 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// int   check_map_size(char *argv)
// {
//     int max_size;
//     char *line;
//     int fd;

//     max_size = 0;
//     line = NULL;
//     fd = open(argv[1], O_RDONLY);
//     if (!fd)
//         err("FILE_OPEN_ERR");
//     while (get_next_line(fd, &line))
//     if (max_size < ft_strlen(line))
//             max_size = ft_strlen(line);
//     save_free(&line);
//     return (max_size);
// }

// int   check_map_width(char *argv)
// {
//     int max_size;
//     char *line;
//     int fd;

//     max_size = 0;
//     line = NULL;
//     fd = open(argv[1], O_RDONLY);
//     if (!fd)
//         err("FILE_OPEN_ERR");
//     while (get_next_line(fd, &line))
//         max_size++;
//     save_free(&line);
//     return (max_size);
// }

// int     *fill_data(char *line, t_data *data)
// {
//     int *a[data->size];
//     int i;

//     i = -1;
//     while (*line && i < data->size)
//     {
//         while (ft_isdigit(*line) && *line)
//             line++;
//         a[++i] = ft_atoi(line);
//         while (!ft_isdigit && *line)
//             line++;
//     }
//     while (i < data->size)
//         a[++i] = 0;
//     return (a);
// }

// t_data    *init_map(char **argv, t_data *data)
// {
//     char *line;
//     int fd;
//     int i;

//     line = NULL;
//     fd = open(argv[1], O_RDONLY);
//     i = -1;
//     if (!fd)
//         err("FILE_OPEN_ERR");
//     while (get_next_line(fd, &line))
//         while (++i < data->width)
//             data->a[i] = fill_data(line, data);
//     save_free(&line);
//     return (data);
// }