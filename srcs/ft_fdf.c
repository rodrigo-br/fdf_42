#include <mlx.h>
#include "../ft_fdf.h"

void	end_program(t_data *mlx)
{
	int y;

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
int	key_hook(int keycode, t_data *mlx)
{
	if (keycode == ESC)
		end_program(mlx);
	else if (keycode == UP)
		mlx->y_axis -= 10;
	else if (keycode == DOWN)
		mlx->y_axis += 10;
	else if (keycode == LEFT)
		mlx->x_axis -= 10;
	else if (keycode == RIGHT)
		mlx->x_axis += 10;
	else if (keycode == W_KEY)
		mlx->angle += 0.1;
	else if (keycode == S_KEY)
		mlx->angle -= 0.1;
	else if (keycode == 65451)
		mlx->zoom += 1;
	else if (keycode == 65453 && mlx->zoom > 1)
		mlx->zoom -= 1;
	else if (keycode == 101)
		mlx->z += 1;
	else if (keycode == 113)
		mlx->z -= 1;
	else
		ft_printf("a tecla apertada foi %d\n", keycode);
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx->img = mlx_new_image(mlx->mlx, 1000, 1000);
	put_points(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
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
	return (0);
}
