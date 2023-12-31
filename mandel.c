/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 01:03:55 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/07 12:52:57 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandel_caluculate(t_complex complex)
{
	t_complex	z;
	int			k;
	double		real;
	double		imag;

	real = 0;
	imag = 0;
	k = 0 ;
	while (k < 100)
	{
		z.real = pow(real, 2.0) - pow(imag, 2.0) + complex.real;
		z.imag = 2 * real * imag + complex.imag;
		real = z.real;
		imag = z.imag;
		if (pow(z.real, 2) + pow(z.imag, 2) > 4.0)
			return (k);
		k++;
	}
	return (k);
}

int	make_mandel(t_data *data)
{
	t_complex	complex;
	int			i;
	int			j;

	i = 0;
	while (i < data->pixel)
	{	
		j = 0 ;
		complex.real = i *(data->size / data->pixel) - (data->size / 2);
		while (j < data->pixel)
		{
			complex.imag = j *(data->size / data->pixel) - (data->size / 2);
			data->divergence = mandel_caluculate(complex);
			my_mlx_pixel_put (data, i, j, pow(data->divergence, 3)
				* data->color_change);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}

//you want to access to pixel but you can only access to address by 1byte(8bits)
//so you have to caluculate the bytes of per_pixel by  bits_per_pixel / 8
// □ : pixel ▫︎ : address
//  □□□□□□
//  ▫︎▫︎▫︎▫︎▫︎▫︎

int	mlx_win_init(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->fractol_type * data->pixel,
			data->pixel, "fractol");
	data->img = mlx_new_image(data->mlx, data->pixel, data->pixel);
	data->addr = mlx_get_data_addr (data->img, &(data->bits_per_pixel),
			&(data->line_length), &(data->endian));
	return (0);
}

static void	set_mandel_param(t_data *data)
{
	data->size = 4;
	data->pixel = 1000;
	data->size_tmp = data->size;
	data->color_change = 1;
	data->fractol_type = MANDELBROT;
}

int	mandelbrot(void)
{
	t_data	data;

	set_mandel_param(&data);
	mlx_win_init(&data);
	make_mandel(&data);
	mlx_key_hook (data.mlx_win, deal_key, &data);
	mlx_hook (data.mlx_win, DESTROYNOTIFY, (1L << 17),
		deal_window_cross, &data);
	mlx_hook (data.mlx_win, BUTTONPRESS, (1L << 4),
		mande_deal_mouse_pointer, &data);
	mlx_loop(data.mlx);
	return (0);
}
