/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:13:07 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/05 20:31:26 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	deal_key(int key, t_data *data)
{
	(void )data;
	if (key == 53)
	{
	printf("OK\n");
	exit (0);
	}
	else
	printf("NO\n");
	return (0);
}

int	deal_window_cross(t_data *data)
{
	(void )data;
	printf("cross\n");
	exit(0);
	return (0);
}

int deal_mouse_pointer(int button, int  x, int y, t_data *data)
{
	// printf("%d\n",button);
	// mlx_mouse_get_pos(data->mlx_win,&x,&y);
	// data->x_pos = x;
	// data->y_pos = y; 

	// (void )x;
	// (void )y;
	printf("%d\n",button);
	// mlx_mouse_get_pos(data->mlx_win,&(data->x_pos),&(data->y_pos));

	
	// printf("x = [%d] y = [%d]\n",data->x_pos, data->y_pos);
	///
	if(button  == 1)
	{
		mlx_destroy_image(data->mlx,data->img);
		data->img = mlx_new_image(data->mlx, 1000, 1000);
		data->addr = mlx_get_data_addr (data->img, &(data->bits_per_pixel),&(data->line_length), &(data->endian));
		
		mlx_mouse_get_pos(data->mlx_win, &x, &y);
		data->x_pos = (double)x;
		data->y_pos = (double)y; 
		printf("x = [%f] y = [%f]\n",data->x_pos, data->y_pos);
		data->x_pos = (data->x_pos) / data->pixel;
		data->y_pos = (data->y_pos) / data->pixel;
		printf("x = [%f] y = [%f]\n",data->x_pos, data->y_pos);
		test(data);
	}
	///
	if(button == 5)
	{
		mlx_destroy_image(data->mlx,data->img);
		data->size *= 0.9;
		data->img = mlx_new_image(data->mlx, 1000, 1000);
		data->addr = mlx_get_data_addr (data->img, &(data->bits_per_pixel),&(data->line_length), &(data->endian));
		test(data);
	}
	else if(button == 4)
	{
		mlx_destroy_image(data->mlx,data->img);
		data->size *= 1.111111;
		data->img = mlx_new_image(data->mlx, 1000, 1000);
		data->addr = mlx_get_data_addr (data->img, &(data->bits_per_pixel),&(data->line_length), &(data->endian));
		test(data);
	}
	return (0);
}