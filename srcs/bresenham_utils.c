/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:50:15 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/22 21:17:57 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fdf.h"

void	add_zoom(t_bres *bres, int zoom)
{
	bres->x[0] *= zoom;
	bres->x[1] *= zoom;
	bres->y[0] *= zoom;
	bres->y[1] *= zoom;
}

void	add_position(t_bres *bres, t_data *data)
{
	bres->x[0] += data->x_axis + data->start;
	bres->x[1] += data->x_axis + data->start;
	bres->y[0] += data->y_axis + data->start;
	bres->y[1] += data->y_axis + data->start;
}

void	add_steps(t_bres *bres)
{
	int	steps;

	bres->delta_x = bres->x[1] - bres->x[0];
	bres->delta_y = bres->y[1] - bres->y[0];
	steps = (ft_n_max(fabs(bres->delta_x), fabs(bres->delta_y)));
	bres->delta_x /= steps;
	bres->delta_y /= steps;
}

void	add_3d(t_bres *bres, t_data *data)
{
	float	temp_x;
	float	temp_y;

	temp_x = (bres->x[0] - bres->y[0]) * cos(data->angle);
	temp_y = (bres->x[0] + bres->y[0]) * sin(data->angle) \
	- (bres->z[0] * data->z);
	bres->x[0] = temp_x;
	bres->y[0] = temp_y;
	temp_x = (bres->x[1] - bres->y[1]) * cos(data->angle);
	temp_y = (bres->x[1] + bres->y[1]) * sin(data->angle) \
	- (bres->z[1] * data->z);
	bres->x[1] = temp_x;
	bres->y[1] = temp_y;
}
