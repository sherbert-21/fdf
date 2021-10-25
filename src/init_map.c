/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:01:58 by sherbert          #+#    #+#             */
/*   Updated: 2021/10/25 20:55:22 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int   check_map_size(char *argv)
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
        if (max_size < ft_strlen(line))
            max_size = ft_strlen(line);
    save_free(&line);
    return (max_size);
}

void    init_map(char **argv, t_data *data)
{
    int max_size;
    char *line;
    
}