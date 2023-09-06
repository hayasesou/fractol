/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:41:52 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/06 21:47:22 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"


# define DestroyNotify 17
# define StructureNotifyMask (1L<<17)
# define ButtonPress	4
# define EnterWindowMask			(1L<<4)


typedef struct t_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		divergence;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	pixel;
	double	size;
	double	size_tmp;

	double	x_pos;
	double	y_pos;

	int		color_change;

}	t_data;

typedef struct t_complex
{
	double	real;
	double	imag;
}	t_complex;

int		deal_key(int key, t_data *data);
int		deal_window_cross(t_data *data);
int		deal_mouse_pointer(int button, int x, int y, t_data *data);
int		make_julia(t_data *data);
int		mandel_caluculate(t_complex complex);
int		make_mandel(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif