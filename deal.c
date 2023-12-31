/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:44:38 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/07 12:34:28 by hfukushi         ###   ########.fr       */
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
	(void)data;
	return (0);
}

int	deal_window_cross(t_data *data)
{
	(void )data;
	ft_printf("window cross is pressed\n");
	exit(0);
	return (0);
}
