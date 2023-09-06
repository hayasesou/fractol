/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_deal_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:34:44 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/07 02:36:52 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int	deal_key(int key, t_data *data)
// {
// 	(void )data;
// 	if (key == 53)
// 	{
// 		ft_printf("ESC key is pressed\n");
// 		exit (0);
// 	}
// 	return (0);
// }

// int	deal_window_cross(t_data *data)
// {
// 	(void )data;
// 	exit(0);
// 	return (0);
// }

// void	zoom_in_out(t_data *data, int button)
// {
// 	if (button == 5)
// 		data->size *= 0.9;
// 	else if (button == 4)
// 		data->size *= 1.1111;
// 	mlx_destroy_image(data->mlx, data->img);
// 	data->img = mlx_new_image(data->mlx, 1000, 1000);
// 	data->addr = mlx_get_data_addr (data->img, &(data->bits_per_pixel),
// 			&(data->line_length), &(data->endian));
// 	make_julia(data);
// }

int	julia_deal_mouse_pointer(int button, int x, int y, t_data *data)
{
	if (button == 1)
	{
		data->size = data->size_tmp;
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, 1000, 1000);
		data->addr = mlx_get_data_addr (data->img, &(data->bits_per_pixel),
				&(data->line_length), &(data->endian));
		mlx_mouse_get_pos(data->mlx_win, &x, &y);
		data->x_pos = (double)x *(data->size / data->pixel) - (data->size / 2);
		data->y_pos = -((double)y *(data->size / data->pixel)
				-(data->size / 2));
		if (data->x_pos <= 2 && data->y_pos <= 2)
			make_julia(data);
	}
	if (button == 5 || button == 4)
		zoom_in_out(data, button);
	return (0);
}

int	deal_mouse_move(int x, int y, t_data *data)
{
	data->size = data->size_tmp;
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, 1000, 1000);
	data->addr = mlx_get_data_addr (data->img, &(data->bits_per_pixel),
			&(data->line_length), &(data->endian));
	mlx_mouse_get_pos(data->mlx_win, &x, &y);
	data->x_pos = (double)x *(data->size / data->pixel) - (data->size / 2);
	data->y_pos = -((double)y *(data->size / data->pixel)
			-(data->size / 2));
	if (data->x_pos <= 2 && data->y_pos <= 2)
		make_julia(data);
	return (0);
}
