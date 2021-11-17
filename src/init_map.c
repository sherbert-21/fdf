/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:01:58 by sherbert          #+#    #+#             */
/*   Updated: 2021/11/16 15:07:35 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int		width_and_heigth_of_map(t_list *file, t_data *data)
{
    char *line;
    int num;

	while (file)
	{
        num = 0;
        line = ft_strdup(file->content);
        while (line && *line)
        {
            while (*line && *line == ' ')
                line++;
            num++;
            while (*line && *line != ' ')
                line++;
        }
        if (data->width < num)
            data->width = num;
        data->height++;
        file = file->next;
	}
    return (SUCCESS);
}

static int  err_check_map(t_list *file)
{
    char    *line;

    while (file)
    {
        line = ft_strdup(file->content);
        while (*line)
	    {
		    if (!(ft_isdigit(*line) || *line == ' ' || *line == '-'))
			    return (ERR);
		    line++;
	    }
        file = file->next;
    }
    return (SUCCESS);
}

static int **file_into_map(t_list *file, t_data *data)
{
    int    **tmp;
    char    *line;
    int     y;
    int     x;

    width_and_heigth_of_map(file, data);
    if (err_check_map(file))
        return (NULL);
    y = -1;
    tmp = ft_calloc(data->height + 1, sizeof(int *));
    while (++y < data->height && tmp)
    {
        x = 0;
        line = ft_strdup(file->content);
        tmp[y] = ft_calloc(data->width + 1, sizeof(int));
        while (*line && line && tmp[y])
        {
            while (*line == ' ' && *line)
                line++;
            tmp[y][x++] = ft_atoi(line);
            while (*line != ' ' && *line)
                line++;
        }
        while (x < data->width && tmp[y])
            tmp[y][x++] = 0;
        file = file->next;
    }
    return (tmp);
}

t_data  *init_map(char *argv, t_data *data)
{
    t_list *file;
	char *line;
	int fd;
    int x;
    int y;

	fd = open(argv, O_RDONLY);
    line = NULL;
    file = NULL;
	while (get_next_line(fd, &line))
        ft_lstadd_back(&file, ft_lstnew(line));
	ft_lstadd_back(&file, ft_lstnew(line));
    data->a = file_into_map(file, data);
    return (data);
}