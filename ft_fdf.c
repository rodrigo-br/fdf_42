/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 00:10:21 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/15 01:47:09 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int main (void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	
	x = 50;
	y = 250;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 300, 300, "capybaras do like banana");	
	while (y != 50)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
		if (y < 100 && y > 75)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x + 50, y, 0xFFFFFF);
			mlx_pixel_put(mlx_ptr, win_ptr, x + 80, y, 0xFFFFFF);
			mlx_pixel_put(mlx_ptr, win_ptr, x + 120, y, 0xFFFFFF);
			mlx_pixel_put(mlx_ptr, win_ptr, x + 150, y, 0xFFFFFF);
		}
		y--;
	}
	while (x != 250)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
		if (x > 100 && x < 130 || x > 170 && x < 200)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y + 25, 0xFFFFFF);
			mlx_pixel_put(mlx_ptr, win_ptr, x, y + 50, 0xFFFFFF);
		}
		if (x > 80 && x < 220)
			mlx_pixel_put(mlx_ptr, win_ptr, x, y + 150, 0xFFFFFF);
		x++;
	}
	while (y != 250)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
		y++;
	}
	while (x != 50)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
		x--;
	}
	mlx_loop(mlx_ptr);
}
