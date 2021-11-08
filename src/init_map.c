/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:01:58 by sherbert          #+#    #+#             */
/*   Updated: 2021/11/08 14:54:04 by sherbert         ###   ########.fr       */
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
    line = get_next_line(fd);
    while (line && *line)
    {
        if (max_size < ft_strlen(line))
                max_size = ft_strlen(line);
        line = get_next_line(fd);
    }
    save_free(&line);
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
    line = get_next_line(fd);
    while (line && *line)
    {
        max_size++;
        line = get_next_line(fd);
    }
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

static int *fill_line(char *line, t_data *data)
{
    int i;
    int *a;

    i = 0;
    while (*line && line)
    {
        while (*line == ' ')
            line++;
        a[i] = ft_atoi(line);
        while (ft_isdigit(*line))
            line++;
        i++;
    }
    while (i < data->width)
    {
        a[i] = 0;
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
    line = get_next_line(fd);
    i = -1;
    while (++i < data->height && (line && *line))
    {
        data->a[i] = fill_line(line, data);
        line = get_next_line(fd);
    }
    save_free(&line);
    return (data);
}