/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:26:45 by sherbert          #+#    #+#             */
/*   Updated: 2021/11/17 17:12:38 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		loop(void *param)
{
	t_data *data;

	data = (t_data *)param;
	draw(data);
	// move_events(data);
	return(SUCCESS);
}

int		key_pressed(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == ESC)
		exit(0);
	// else if (key == _LEFT && data->key->left == 0)
	// 	data->key->left = 1;
	// else if (key == _RIGHT && data->key->right == 0)
	// 	data->key->right = 1;
	// else if (key == _UP && data->key->up == 0)
	// 	data->key->up = 1;
	// else if (key == _DOWN && data->key->down == 0)
	// 	data->key->down = 1;
	// else if (key == W && data->key->turn_up == 0)
	// 	data->key->turn_up = 1;
	// else if (key == S && data->key->turn_down == 0)
	// 	data->key->turn_down = 1;
	// else if (key == A && data->key->turn_left == 0)
	// 	data->key->turn_left = 1;
	// else if (key == D && data->key->turn_right == 0)
	// 	data->key->turn_right = 1;
	return (SUCCESS);
}

// int		key_released(int key, void *param)
// {
// 	t_data	*data;

// 	data = (t_data *)param;
// 	if (key == _LEFT && data->key->left == 1)
// 		data->key->left = 0;
// 	else if (key == _RIGHT && data->key->right == 1)
// 		data->key->right = 0;
	// else if (key == _UP && data->key->up == 1)
	// 	data->key->up = 0;
	// else if (key == _DOWN && data->key->down == 1)
	// 	data->key->down = 0;
	// else if (key == W && data->key->turn_up == 1)
	// 	data->key->turn_up = 0;
	// else if (key == S && data->key->turn_down == 1)
	// 	data->key->turn_down = 0;
	// else if (key == A && data->key->turn_left == 1)
	// 	data->key->turn_left = 0;
	// else if (key == D && data->key->turn_right == 1)
	// 	data->key->turn_right = 0;
// 	return (SUCCESS);
// }

int		event_destroy_window(void *param)
{
	t_data *data;

	data = (t_data *)param;
	exit(0);
	return (SUCCESS);
}

int					move_events(t_data *data)
{
	if (data->key->left == 1)
		left(data);
	else if (data->key->right == 1)
		right(data);
    else if (data->key->down == 1)
		down(data);
	else if (data->key->up == 1)
		up(data);
	// else if (data->key->turn_left == 1)
	// 	turn_left(data);
	// else if (data->key->turn_right == 1)
	// 	turn_right(data);
	// else if (data->key->turn_up == 1)
	// 	turn_up(data);
	// else if (data->key->turn_down == 1)
	// 	turn_down(data);
	return (SUCCESS);
}