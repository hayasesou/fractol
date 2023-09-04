/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:13:07 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/04 14:21:26 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int deal_mouse(int button, int x,int y, t_data *data)
{
	if(button == 5)
	{
		printf("%d\n",button);
	}
	else if ( button ==4)
	{
		printf("%d\n",button);
	}
	return (0);
}
