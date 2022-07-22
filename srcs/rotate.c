/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:58:10 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/22 21:15:39 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fdf.h"

static void	rotate_alpha(t_bres *bres, t_data *data)
{
	bres->y[2] = bres->y[0];
	bres->z[2] = bres->z[0] * data->z;
	bres->y[0] = bres->y[2] * cos(data->alpha) - bres->z[2] * sin(data->alpha);
	bres->z[0] = bres->y[2] * sin(data->alpha) + bres->z[2] * cos(data->alpha);
	bres->y[2] = bres->y[1];
	bres->z[2] = bres->z[1] * data->z;
	bres->y[1] = bres->y[2] * cos(data->alpha) - bres->z[2] * sin(data->alpha);
	bres->z[1] = bres->y[2] * sin(data->alpha) + bres->z[2] * cos(data->alpha);
}

static void	rotate_beta(t_bres *bres, t_data *data)
{
	bres->x[2] = bres->x[0];
	bres->z[2] = bres->z[0] * data->z;
	bres->x[0] = bres->x[2] * cos(data->beta) + bres->z[2] * sin(data->beta);
	bres->z[0] = -bres->x[2] * sin(data->beta) + bres->z[2] * cos(data->beta);
	bres->x[2] = bres->x[1];
	bres->z[2] = bres->z[1] * data->z;
	bres->x[1] = bres->x[2] * cos(data->beta) + bres->z[2] * sin(data->beta);
	bres->z[1] = -bres->x[2] * sin(data->beta) + bres->z[2] * cos(data->beta);
}

static void	rotate_gamma(t_bres *bres, t_data *data)
{
	bres->x[2] = bres->x[0];
	bres->y[2] = bres->y[0];
	bres->x[0] = bres->x[2] * cos(data->gamma) - bres->y[2] * sin(data->gamma);
	bres->y[0] = bres->x[2] * sin(data->gamma) + bres->y[2] * cos(data->gamma);
	bres->x[2] = bres->x[1];
	bres->y[2] = bres->y[1];
	bres->x[1] = bres->x[2] * cos(data->gamma) - bres->y[2] * sin(data->gamma);
	bres->y[1] = bres->x[2] * sin(data->gamma) + bres->y[2] * cos(data->gamma);
}

// The index 2 are being used to hold a temporary value
void	rotate(t_bres *bres, t_data *data)
{
	rotate_alpha(bres, data);
	rotate_beta(bres, data);
	rotate_gamma(bres, data);
}
