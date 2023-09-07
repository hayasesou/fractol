/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 01:48:51 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/07 09:18:23 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		ft_printf("error : invalid parameter.\n");
		ft_printf("please input -> ./fractol <FRACTOL>\n");
		ft_printf("FRACTOL : mandelbrot, julia\n");
		return (1);
	}
	if (ft_memcmp(av[1], "mandelbrot", 11) == 0)
		mandelbrot();
	else if (ft_memcmp(av[1], "julia", 6) == 0)
		julia();
	else
	{
		ft_printf("error : invalid fractol.\n");
		ft_printf("FRACTOL : mandelbrot, julia\n");
	}
	return (0);
}