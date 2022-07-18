#include <mlx.h>
#include <limits.h>
#include "../ft_fdf.h"

int	key_hook(int keycode, t_data *mlx)
{
	int	x;
	int y;

	if (keycode == ESC)
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		while(y < mlx->y_lines)
		{
			free(mlx->matrix_boladona[y]);
			y++;
		}
		free(mlx->matrix_boladona);
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

int	fdf(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1000, 1000, "Socorro!");
	data->img = mlx_new_image(data->mlx, 1000, 1000);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
&data->line_length, &data->endian);
	put_points(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_key_hook(data->win, key_hook, data);
	mlx_loop(data->mlx);
}
