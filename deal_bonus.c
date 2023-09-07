/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:35:37 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/07 12:45:18 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	deal_key(int key, t_data *data)
{
	if (key == MAC_ESC_KEY)
	{
		ft_printf("ESC key is pressed\n");
		exit (0);
	}
	if (key == MAC_SPACE_KEY)
	{
		data->color_change += 1;
		updata_image_data(data);
		if (data->fractol_type == MANDELBROT)
			make_mandel(data);
		else if (data->fractol_type == JULIA)
			make_julia(data);
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
