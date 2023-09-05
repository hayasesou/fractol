#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>

#define DestroyNotify			17
#define StructureNotifyMask		(1L<<17)
#define ButtonPress		4
#define EnterWindowMask			(1L<<4)


typedef struct t_data
{
	void 	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		divergence;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	pixel;
	double	size;

	double x_pos;
	double y_pos;
} t_data;

// typedef struct t_database
// {
// 	t_data *data;
// 	t_data enlarge;
// 	t_data shrink;
// }	t_database;

typedef struct t_complex
{
	double real;
	double imag;
} t_complex;

int deal_key(int key, t_data *data);
int deal_window_cross(t_data *data);
int deal_mouse_pointer(int button, int  x, int y, t_data *data);
int test(t_data *data);

#endif