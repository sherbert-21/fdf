/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:26:45 by sherbert          #+#    #+#             */
/*   Updated: 2021/11/10 10:30:59 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// int		loop(void *param)
// {
// 	t_data *data;

// 	data = (t_data *)param;
// 	ray(data);
// 	move_events(data);
// 	return (SUCCESS);
// }

// int		key_pressed(int key, void *param)
// {
// 	t_data	*data;

// 	data = (t_data *)param;
// 	if (key == ESC)
// 		exit(0);
// 	else if (key == W && data->keybuffer->forward == 0)
// 		data->keybuffer->forward = 1;
// 	else if (key == S && data->keybuffer->backward == 0)
// 		data->keybuffer->backward = 1;
// 	else if (key == A && data->keybuffer->left == 0)
// 		data->keybuffer->left = 1;
// 	else if (key == D && data->keybuffer->right == 0)
// 		data->keybuffer->right = 1;
// 	else if (key == _LEFT && data->keybuffer->turn_left == 0)
// 		data->keybuffer->turn_left = 1;
// 	else if (key == _RIGHT && data->keybuffer->turn_right == 0)
// 		data->keybuffer->turn_right = 1;
// 	return (SUCCESS);
// }

// int		key_released(int key, void *param)
// {
// 	t_data	*data;

// 	data = (t_data *)param;
// 	if ((key == W) && data->keybuffer->forward == 1)
// 		data->keybuffer->forward = 0;
// 	else if ((key == S) && data->keybuffer->backward == 1)
// 		data->keybuffer->backward = 0;
// 	else if (key == A && data->keybuffer->left == 1)
// 		data->keybuffer->left = 0;
// 	else if (key == D && data->keybuffer->right == 1)
// 		data->keybuffer->right = 0;
// 	else if (key == _LEFT && data->keybuffer->turn_left == 1)
// 		data->keybuffer->turn_left = 0;
// 	else if (key == _RIGHT && data->keybuffer->turn_right == 1)
// 		data->keybuffer->turn_right = 0;
// 	return (0);
// }

int		event_destroy_window(void *param)
{
	t_data *data;

	data = (t_data *)param;
	exit(0);
	return (SUCCESS);
}