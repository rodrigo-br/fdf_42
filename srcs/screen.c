/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:57:29 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/22 20:57:30 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (y > HEIGHT || x > WIDTH - MENU_WIDTH || x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	menu(t_data *data)
{
	int	menu_pos;
	int	w;
	int	line;

	w = 0xFFFFFF;
	menu_pos = WIDTH - MENU_WIDTH + 10;
	line = HEIGHT;
	while (line)
	{
		mlx_pixel_put(data->mlx, data->win, menu_pos - 10, line, w);
		line--;
	}
	mlx_string_put(data->mlx, data->win, menu_pos, 25, w, "Close : Esc");
	mlx_string_put(data->mlx, data->win, menu_pos, 50, w, "Change 2D/3D: Space");
	mlx_string_put(data->mlx, data->win, menu_pos, 75, w, "Move : arrows");
	mlx_string_put(data->mlx, data->win, menu_pos, 100, w, "Zoom : scroll or +/-");
	mlx_string_put(data->mlx, data->win, menu_pos, 125, w, "Spin Z : Z/X");
	mlx_string_put(data->mlx, data->win, menu_pos, 150, w, "Rotate Z : Q/E");
	mlx_string_put(data->mlx, data->win, menu_pos, 175, w, "Rotate X : W/S");
	mlx_string_put(data->mlx, data->win, menu_pos, 200, w, "Rotate Y : A/D");
	mlx_string_put(data->mlx, data->win, menu_pos, 225, w, "3D Depth : M/N");
	mlx_string_put(data->mlx, data->win, menu_pos, 250, w, "Color White : Click");
	mlx_string_put(data->mlx, data->win, menu_pos, 275, w, "Reset : Enter");
}

int	rerender(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIDTH - MENU_WIDTH, HEIGHT);
	put_points(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	menu(data);
	return (0);
}

int	fdf(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "s2");
	data->img = mlx_new_image(data->mlx, WIDTH - MENU_WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
&data->line_length, &data->endian);
	put_points(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	menu(data);
	mlx_hook(data->win, KEY_PRESS_EVENT, KEY_PRESS_MASK, key_hook, data);
	mlx_hook(data->win, MOUSE_PRESS_EVENT, MOUSE_PRESS_MASK, mouse_hook, data);
	mlx_hook(data->win, DESTROY_EVENT, MOUSE_PRESS_MASK, end_program, data);
	mlx_hook(data->win, ENTER_EVENT, ENTER_WINDOW_MASK, rerender, data);
	mlx_loop(data->mlx);
	return (0);
}
