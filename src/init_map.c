/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:01:58 by sherbert          #+#    #+#             */
/*   Updated: 2021/11/09 17:42:32 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static t_list *take_list(char *argv)
{
	t_list *list;
	char *line;
	int fd;

	fd = open(argv, O_RDONLY);
	line = NULL;
	while (get_next_line(fd, &line))
		ft_lstadd_back(&list, ft_lstnew(line));
	ft_lstadd_back(&list, ft_lstnew(line));
	return (list);
}

static void		width_and_heigth_of_map(t_list *file, t_data *data)
{
	while (file)
	{
		if (data->width < ft_strlen(file->content))
			data->width = ft_strlen(file->content);
		data->height++;
		file = file->next;
	}
}

static int  *fill_line(char *line, t_data *data)
{
    int *tmp;
    int x;

    x = -1;
    tmp = ft_calloc(data->width + 1, sizeof(int));
    if (!tmp)
        return (NULL);
    while (*line && line)
    {
        while (*line == ' ')
            line++;
        if (!(ft_isdigit(*line) || *line == '-'))
            return (NULL);
        tmp[++x] = ft_atoi(line);
        while (*line != ' ')
        {
            if (!(ft_isdigit(*line) || *line == '-'))
                return (NULL);
            line++;
        }
    }
    while (++x < data->width)
        tmp[x] = 0;
    return (tmp);
}

static int			**file_into_map(t_list *file, t_data *data)
{
	int	    **tmp;
	char	*line;
	int		y;

	y = -1;
	width_and_heigth_of_map(file, data);
    tmp = ft_calloc(data->height + 1, sizeof(int *));
	if (!tmp)
		return(NULL);
	while (++y < data->height)
	{
		line = ft_strdup(file->content);
		tmp[y] = fill_line(line, data);
        if (!tmp[y])
            return (NULL);
		ft_lstdelone(file, save_free);
        save_free(&line);
		file = file->next;
	}
	return (tmp);
}

t_data  *init_map(char *argv, t_data *data)
{
   t_list *list;

   list = take_list(argv);
   data->a = file_into_map(list, data);
   if (!data->a)
        return(NULL);
    else
        return (data->a);
}