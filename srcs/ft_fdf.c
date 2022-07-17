#include <mlx.h>
#include <limits.h>
#include "../ft_fdf.h"

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

int	key_hook(int keycode, t_data *mlx)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		exit(0);
	}
	else
		ft_printf("a tecla apertada foi %d\n", keycode);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_data	fdf;
	int		x;
	int		y;

	x = 50;
	y = 250;
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 300, 300, "Camilla s2");
	fdf.img = mlx_new_image(fdf.mlx, 300, 300);
	fdf.addr = mlx_get_data_addr(fdf.img, &fdf.bits_per_pixel, \
&fdf.line_length, &fdf.endian);
	while (y != 50)
	{
		my_mlx_pixel_put(&fdf, x, y, 0xFFFFFF);
		y--;
	}
	while (x != 250)
	{
		my_mlx_pixel_put(&fdf, x, y, 0xFFFFFF);
		if (x > 100 && x < 130 || x > 170 && x < 200)
		{
			my_mlx_pixel_put(&fdf, x, y + 50, 0xFFFFFF);
		}
		if (x > 80 && x < 220)
			my_mlx_pixel_put(&fdf, x, y + 150, 0xFFFFFF);
		x++;
	}
	while (y != 250)
	{
		my_mlx_pixel_put(&fdf, x, y, 0xFFFFFF);
		y++;
	}
	while (x != 50)
	{
		my_mlx_pixel_put(&fdf, x, y, 0xFFFFFF);
		x--;
	}
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img, 0, 0);
	mlx_key_hook(fdf.win, key_hook, &fdf);
	mlx_loop(fdf.mlx);
}