/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:13:07 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/05 14:32:02 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	deal_key(int key, t_data *data)
{
	if (key == 53)
	{
	printf("OK\n");
	mlx_destroy_window (data->mlx, data->mlx_win);
	exit (0);
	}
	else
	printf("NO\n");
	return (0);
}

int	deal_window_cross(t_data *data)
{
	printf("cross\n");
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
	return (0);
}

int deal_mouse_pointer(int button,int x,int y,t_data *data)
{
	printf("%d\n",button);
		mlx_mouse_get_pos(data->mlx_win,&x,&y);
	printf("x = [%d] y = [%d]\n", x, y);
	if(button == 5)
	{
		mlx_clear_window(data->mlx,data->mlx_win);
		data->size *= 0.9;
		test(data);
	}
	else if(button == 4)
	{
		mlx_clear_window(data->mlx,data->mlx_win);
		data->size *= 1.111111;
		test(data);
	}
	return (0);
}