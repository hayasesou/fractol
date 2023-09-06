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
	if(button  == 1)
	{
		mlx_destroy_image(data->mlx,data->img);
		data->img = mlx_new_image(data->mlx, 1000, 1000);
		data->addr = mlx_get_data_addr (data->img, &(data->bits_per_pixel),&(data->line_length), &(data->endian));
		
		mlx_mouse_get_pos(data->mlx_win, &x, &y);
		printf("x = [%f], y = [%f]\n", (double)x, (double)y);
		data->x_pos = (double)x *(data->size / data->pixel) - (data->size / 2);
		data->y_pos = (double)y *(data->size / data->pixel) - (data->size / 2);
		printf("x = [%f], y = [%f]\n",data->x_pos, data->y_pos);
		if( data->x_pos <=2 && data->y_pos <= 2 )
			make_julia(data);
	}
	if(button == 5)
	{
		mlx_destroy_image(data->mlx,data->img);
		data->size *= 0.9;
		data->img = mlx_new_image(data->mlx, 1000, 1000);
		data->addr = mlx_get_data_addr (data->img, &(data->bits_per_pixel),&(data->line_length), &(data->endian));
		make_julia(data);
	}
	else if(button == 4)
	{
		mlx_destroy_image(data->mlx,data->img);
		data->size *= 1.111111;
		data->img = mlx_new_image(data->mlx, 1000, 1000);
		data->addr = mlx_get_data_addr (data->img, &(data->bits_per_pixel),&(data->line_length), &(data->endian));
		make_julia(data);
	}
	return (0);
}