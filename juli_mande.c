# include "fractol.h"

int mandel_caluculate(t_complex complex)
{
	t_complex z;
	int	k;
	double real = 0 ;
	double imag = 0 ;

	k = 0 ;
	if(complex.real == 0 || complex.imag == 0)
		return(-1);
	while (k < 100)
	{
		z.real = pow(real,2.0) - pow(imag,2.0) + complex.real;
		z.imag = 2 * real * imag + complex.imag;
		real = z.real;
		imag = z.imag;
		if (pow(z.real,2)+ pow(z.imag,2) > 4.0 )
			return (k);
		k++;
	}
	return (k);
}

int make_mandel(t_data *data)
{
	t_complex complex;
	int i;
	int j;

	i = 0;
	while (i < data->pixel)
	{	
		j = 0 ;
		complex.real = i *(data->size / data->pixel) - (data->size / 2);
		while (j < data->pixel)
			{
				complex.imag = j *(data->size /data->pixel) - (data->size / 2);
				data->divergence = mandel_caluculate(complex);
				if( i == data->pixel / 2 || j == data->pixel / 2)
					my_mlx_pixel_put (data, i, j,0X00EE82EE);
				else
					my_mlx_pixel_put (data, i, j,pow(data->divergence,4));
				j++;
			}
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}
