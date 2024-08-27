/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:09:09 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/07 12:29:39 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	if (data->divergence == 100 || x == data->pixel -1)
		*(unsigned int *)dst = WHITE;
	else if (data->divergence == 0)
		*(unsigned int *)dst = BLACK;
	else
		*(unsigned int *)dst = color;
}

void	updata_image_data(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, 1000, 1000);
	data->addr = mlx_get_data_addr (data->img, &(data->bits_per_pixel),
			&(data->line_length), &(data->endian));
}

void	zoom_in_out(t_data *data, int button)
{
	printf("zoom_in_out\n");
	if (button == MOUSE_WHEEL_FORWARD)
		data->size *= 0.9;
	else if (button == MOUSE_WHEEL_BACKWARD)
		data->size *= 1.1111;
	updata_image_data(data);
	if (data->fractol_type == MANDELBROT)
		make_mandel(data);
	else if (data->fractol_type == JULIA)
		make_julia(data);
}
