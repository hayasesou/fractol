/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_deal_mlx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:13:07 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/07 12:27:25 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mande_deal_mouse_pointer(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == MOUSE_LEFT_CLICK)
	{
		data->size = data->size_tmp;
		updata_image_data(data);
		make_mandel(data);
	}
	if (button == MOUSE_WHEEL_FORWARD || button == MOUSE_WHEEL_BACKWARD)
		zoom_in_out(data, button);
	return (0);
}
