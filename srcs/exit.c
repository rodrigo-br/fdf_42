/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:55:35 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/22 21:17:23 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fdf.h"

int	end_program(t_data *mlx)
{
	int	y;

	y = 0;
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	while (y < mlx->y_lines)
	{
		free(mlx->matrix_boladona[y]);
		y++;
	}
	free(mlx->matrix_boladona);
	exit(0);
	return (0);
}

int	exit_error(int erro)
{
	if (erro == 1)
		ft_printf("Número de argumentos inválido.\n");
	else if (erro == 2)
		ft_printf("Arquivo inválido.\n");
	else
		ft_printf("Mapa inválido.\n");
	return (-1);
}
