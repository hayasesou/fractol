#include <stdio.h>
#include "fractol.h"

//we want to access to pixel but we can only access to address by 1byte(8 bits) 
//so you have to caluculate the bytes of per_pixel by  bits_per_pixel / 8
// □ : pixel ▫︎ : address
//  □□□□□□
//  ▫︎▫︎▫︎▫︎▫︎▫︎

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	if( data->divergence != 0)
	*(unsigned int*)dst = color / data->divergence;

}

int caluculate(t_complex complex,double x, double y)
{
	t_complex z;
	int	k;

	k = 0 ;
	while (k < 100)
	{
		z.real = pow(x,2.0) - pow(y,2.0) + complex.real;
		z.imag = 2 * x * y + complex.imag;
		x = z.real;
		y = z.imag;
		if (pow(z.real,2)+ pow(z.imag,2) > 4.0 )
			return (k);
		k++;
	}
	return (k);
}

int test(t_data *data)
{
	t_complex complex;
	int i;
	int j;
	double x, y;
	
	complex.real = data->x_pos;
	complex.imag = data->y_pos;
	i = 0;
	while (i < data->pixel)
	{	
		j = 0 ;
		x = i *(data->size / data->pixel) - (data->size / 2);
		while (j < data->pixel)
			{
				y = j *(data->size /data->pixel) - (data->size / 2);
				data->divergence =caluculate(complex, x, y);
				my_mlx_pixel_put (data, i, j, 0x00FFFFFF);
				j++;
			}
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}

int mlx_win_init(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 2000, 1000, "fractol");
	data->img = mlx_new_image(data->mlx, 1000, 1000);
	data->addr = mlx_get_data_addr (data->img, &(data->bits_per_pixel),&(data->line_length), &(data->endian));
	return (0);	
}

int	main ()
{
	t_data	data;
	data.size = 4;
	data.pixel = 1000;

	mlx_win_init(&data);
	mlx_key_hook (data.mlx_win, deal_key, &data);
	mlx_hook (data.mlx_win, ButtonPress, EnterWindowMask, deal_mouse_pointer, &data);
	mlx_hook (data.mlx_win, DestroyNotify, StructureNotifyMask, deal_window_cross, &data);
	mlx_loop(data.mlx);

	return (0);
}
