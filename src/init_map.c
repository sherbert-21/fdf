/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:01:58 by sherbert          #+#    #+#             */
/*   Updated: 2021/11/08 18:26:27 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int   check_map_width(char *argv)
{
    int max_size;
    char *line;
    int fd;

    max_size = 0;
    line = NULL;
    fd = open(argv[1], O_RDONLY);
    if (!fd)
        err("FILE_OPEN_ERR");
    while (get_next_line(fd, &line))
    {
        ft_printf("%s", line);
        if(max_size < ft_strlen(line))
            max_size = ft_strlen(line);
    }
    save_free(&line);
    ft_printf("%d\n", max_size);
    return (max_size);
}

int   check_map_height(char *argv)
{
    int max_size;
    char *line;
    int fd;

    max_size = 0;
    line = NULL;
    fd = open(argv[1], O_RDONLY);
    if (!fd)
        err("FILE_OPEN_ERR");
    while (get_next_line(fd, &line))
        max_size++;
    ft_printf("%d", max_size);
    save_free(&line);
    return (max_size);
}

// int     *fill_data(char *line, t_data *data)
// {
//     int *a[data->width];
//     int i;

//     i = -1;
//     while (*line && i < data->width)
//     {
//         while (ft_isdigit(*line) && *line)
//             line++;
//         a[++i] = ft_atoi(line);
//         while (!ft_isdigit && *line)
//             line++;
//     }
//     while (i < data->width)
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

static int *fill_line(char *line, int j, t_data *data)
{
    int i;
    int *a;

    i = 0;
    while (*line && line)
    {
        while (*line == ' ')
            line++;
        data->a[j][i] = ft_atoi(line);
        while (ft_isdigit(*line))
            line++;
        i++;
    }
    while (i < data->width)
    {
        data->a[j][i] = 0;
        i++;
    }
    return (a);
}

t_data  *init_map(char *argv, t_data *data)
{
    char *line;
    int fd;
    int i;

    fd = open(argv, O_RDONLY);
    line = NULL;
    i = -1;
    while (++i < data->height && get_next_line(fd, &line))
        data = fill_line(line, i, data);
    save_free(&line);
    return (data);
}