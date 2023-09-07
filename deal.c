/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:44:38 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/07 09:45:43 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	deal_key(int key, t_data *data)
{
	(void )data;
	if (key == 53)
	{
		ft_printf("ESC key is pressed\n");
		exit (0);
	}
	return (0);
}

int	deal_window_cross(t_data *data)
{
	(void )data;
	ft_printf("window cross is pressed\n");
	exit(0);
	return (0);
}

void	zoom_in_out(t_data *data, int button)
{
	if (button == 5)
		data->size *= 0.9;
	else if (button == 4)
		data->size *= 1.1111;
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, 1000, 1000);
	data->addr = mlx_get_data_addr (data->img, &(data->bits_per_pixel),
			&(data->line_length), &(data->endian));
	if (data->fractol_type == MANDELBROT)
		make_mandel(data);
	else if (data->fractol_type == JULIA)
		make_julia(data);
}
