/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:32:25 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/07 12:31:48 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_caluculate(t_complex complex, double x, double y)
{
	t_complex	z;
	int			k;

	k = 0 ;
	while (k < 100)
	{
		z.real = pow(x, 2.0) - pow(y, 2.0) + complex.real;
		z.imag = 2 * x * y + complex.imag;
		x = z.real;
		y = z.imag;
		if (pow(z.real, 2) + pow(z.imag, 2) > 4.0)
			return (k);
		k++;
	}
	return (k);
}

//you want to access to pixel but you can only access to address by 1byte(8bits)
//so you have to caluculate the bytes of per_pixel by  bits_per_pixel / 8
// □ : pixel ▫︎ : address
//  □□□□□□
//  ▫︎▫︎▫︎▫︎▫︎▫︎

int	make_julia(t_data *data)
{
	t_complex	complex;
	int			i;
	int			j;
	double		x;
	double		y;

	complex.real = data->x_pos;
	complex.imag = data->y_pos;
	i = 0;
	while (i < data->pixel)
	{	
		j = 0 ;
		x = i *(data->size / data->pixel) - (data->size / 2);
		while (j < data->pixel)
		{
			y = -(j *(data->size / data->pixel) - (data->size / 2));
			data->divergence = julia_caluculate(complex, x, y);
			my_mlx_pixel_put (data, i, j, pow(data->divergence, 3)
				* data->color_change);
				j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 1000, 0);
	return (0);
}

static void	set_julia_param(t_data *data)
{
	data->size = 4;
	data->pixel = 1000;
	data->size_tmp = data->size;
	data->color_change = 1;
	data->fractol_type = JULIA;
}

int	julia(void)
{
	t_data	data;

	set_julia_param(&data);
	mlx_win_init(&data);
	make_mandel(&data);
	mlx_key_hook (data.mlx_win, deal_key, &data);
	mlx_hook (data.mlx_win, DESTROYNOTIFY, (1L << 17),
		deal_window_cross, &data);
	mlx_hook (data.mlx_win, MOTIONNOTIFY, (1L << 6),
		deal_mouse_move, &data);
	mlx_hook (data.mlx_win, BUTTONPRESS, (1L << 4),
		julia_deal_mouse_pointer, &data);
	printf("Window created: %p\n", data.mlx_win);
	mlx_loop(data.mlx);
	return (0);
}

