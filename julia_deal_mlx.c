/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_deal_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:34:44 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/07 11:38:49 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_deal_mouse_pointer(int button, int x, int y, t_data *data)
{
	if (button == MOUSE_LEFT_CLICK)
	{
		data->size = data->size_tmp;
		updata_image_data(data);
		mlx_mouse_get_pos(data->mlx_win, &x, &y);
		data->x_pos = (double)x *(data->size / data->pixel) - (data->size / 2);
		data->y_pos = -((double)y *(data->size / data->pixel)
				-(data->size / 2));
		if (data->x_pos <= 2 && data->y_pos <= 2)
			make_julia(data);
	}
	if (button == MOUSE_WHEEL_FORWARD || button == MOUSE_WHEEL_BACKWARD)
		zoom_in_out(data, button);
	return (0);
}

int	deal_mouse_move(int x, int y, t_data *data)
{
	data->size = data->size_tmp;
	updata_image_data(data);
	mlx_mouse_get_pos(data->mlx_win, &x, &y);
	data->x_pos = (double)x *(data->size / data->pixel) - (data->size / 2);
	data->y_pos = -((double)y *(data->size / data->pixel)
			-(data->size / 2));
	if (data->x_pos <= 2 && data->y_pos <= 2)
		make_julia(data);
	return (0);
}
