/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_deal_mlx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:13:07 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/07 09:23:24 by hfukushi         ###   ########.fr       */
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

int	mande_deal_mouse_pointer(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 5 || button == 4)
		zoom_in_out(data, button);
	return (0);
}

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;
// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	if (data->divergence == 100 || x == data->pixel -1)
// 		*(unsigned int *)dst = 0X00FFFFFF;
// 	else if (data->divergence == 0)
// 		*(unsigned int *)dst = 0X00000000;
// 	else
// 		*(unsigned int *)dst = color;
// }