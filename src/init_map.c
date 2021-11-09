/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:01:58 by sherbert          #+#    #+#             */
/*   Updated: 2021/11/09 20:59:44 by sherbert         ###   ########.fr       */
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

static int  *fill_line(char *line, t_data *data)
{
    int *tmp;
    int x;

    x = 0;
    tmp = ft_calloc(data->width + 1, sizeof(int));
    if (!tmp)
        return (NULL);
    while (*line && line)
    {
        while (*line == ' ')
            line++;
        tmp[x] = ft_atoi(line);
        x++;
        while (*line != ' ')
            line++;
    }
    while (x < data->width)
        tmp[x++] = 0;
    return (tmp);
}

static int			**file_into_map(t_list *file, t_data *data)
{
	int	    **tmp;
	char	*line;
	int		y;

	y = -1;
	if (width_and_heigth_of_map(file, data))
        return (NULL);
    tmp = ft_calloc(data->height + 1, sizeof(int *));
	if (!tmp)
		return(NULL);
	while (++y < data->height && file)
	{
		line = ft_strdup(file->content);
		tmp[y] = fill_line(line, data);
        if (!tmp[y])
            return (NULL);
		ft_lstdelone(file, free);
		file = file->next;
	}
	return (tmp);
}

t_data  *init_map(char *argv, t_data *data)
{
    t_list *file;
	char *line;
	int fd;

	fd = open(argv, O_RDONLY);
    line = NULL;
    file = NULL;
	while (get_next_line(fd, &line))
        ft_lstadd_back(&file, ft_lstnew(line));
	ft_lstadd_back(&file, ft_lstnew(line));
    data->a = file_into_map(file, data);
    ft_printf("yos");
    if (!data->a)
        data = free_data(data);
    return (data);
}