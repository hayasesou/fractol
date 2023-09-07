/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukushi <hfukushi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:41:52 by hfukushi          #+#    #+#             */
/*   Updated: 2023/09/07 10:13:33 by hfukushi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

# define DESTROYNOTIFY 17
# define BUTTONPRESS	4
# define MOTIONNOTIFY	6

# define MANDELBROT 1
# define JULIA 2

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

	int		fractol_type;
}	t_data;

typedef struct t_complex
{
	double	real;
	double	imag;
}	t_complex;

void	auxiliary_line(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

int		deal_mouse_move(int x, int y, t_data *data);
int		deal_key(int key, t_data *data);
int		deal_window_cross(t_data *data);

int		mlx_win_init(t_data *data);
void	zoom_in_out(t_data *data, int button);

int		mandelbrot(void);
int		make_mandel(t_data *data);
int		mandel_caluculate(t_complex complex);
int		mande_deal_mouse_pointer(int button, int x, int y, t_data *data);

int		julia(void);
int		make_julia(t_data *data);
int		julia_caluculate(t_complex complex, double x, double y);
int		julia_deal_mouse_pointer(int button, int x, int y, t_data *data);

#endif