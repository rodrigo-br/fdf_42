#include <mlx.h>
#include "../ft_fdf.h"

int	end_program(t_data *mlx)
{
	int y;

	y = 0;
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
	return (0);
}

static int	pimba(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	put_points(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	key_hook(int keycode, t_data *mlx)
{
	ft_printf("keycode = %d\n", keycode);
	if (keycode == ESC)
		end_program(mlx);
	if (keycode == UP)
		mlx->y_axis += 50;
	else if (keycode == DOWN)
		mlx->y_axis -= 50;
	else if (keycode == LEFT)
		mlx->x_axis += 50;
	else if (keycode == RIGHT)
		mlx->x_axis -= 50;
	else if (keycode == W_KEY)
		mlx->angle += 0.1;
	else if (keycode == S_KEY)
		mlx->angle -= 0.1;
	else if (keycode == PLUS_KEY)
		mlx->zoom += 1;
	else if (keycode == MINUS_KEY && mlx->zoom > 1)
		mlx->zoom -= 1;
	else if (keycode == E_KEY)
		mlx->z += 1;
	else if (keycode == Q_KEY)
		mlx->z -= 1;
	else if (keycode == SPACE)
		mlx->projection += 1;
	pimba(mlx);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (y > HEIGHT || x > WIDTH || x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	mouse_release(int keycode, int x, int y, t_data *mlx)
{
	(void)x;
	(void)y;
	mlx->test = 0;
	mlx->zoom += 1;
	printf("ENTROU\n");
	pimba(mlx);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_data *mlx)
{
	(void)y;
	(void)x;
	ft_printf("keycode = %d\n", keycode);
	if (keycode == 5 && mlx->zoom > 1)
		mlx->zoom -= 1;
	else if (keycode == 4)
		mlx->zoom += 1;
	pimba(mlx);
	return (0);
}

int	fdf(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "y mars leak?");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
&data->line_length, &data->endian);
	put_points(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_hook(data->win, KEY_PRESS_EVENT, KEY_PRESS_MASK, key_hook, data);
	//mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_hook(data->win, 04, 1L<<2, mouse_hook, data);
	mlx_hook(data->win, DESTROY_EVENT, 0, end_program, data);
	mlx_hook(data->win, ENTER_EVENT, 0, pimba, data);
	mlx_loop(data->mlx);
	return (0);
}
