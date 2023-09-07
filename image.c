/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:09:09 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/07 10:14:37 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	if (data->divergence == 100 || x == data->pixel -1)
		*(unsigned int *)dst = 0X00FFFFFF;
	else if (data->divergence == 0)
		*(unsigned int *)dst = 0X00000000;
	else
		*(unsigned int *)dst = color;
}

void	auxiliary_line(t_data *data)
{
	mlx_string_put(data->mlx, data->mlx_win, data->pixel - 30,
		data->pixel / 2 +1, 15631086, "real");
	mlx_string_put(data->mlx, data->mlx_win, data->pixel / 2 - 15,
		10, 15631086, "imag");
}
