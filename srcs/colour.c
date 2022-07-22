/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:19:27 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/22 21:21:10 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fdf.h"

void	check_color_max(int n, t_data *data)
{
	if (n < 0)
	{
		n = abs(n);
		if (data->color_hold < (unsigned int)n)
			data->color_hold = n;
		if ((unsigned int)n > data->color_max + n)
			data->color_max = n;
		if ((unsigned int)n < data->color_min + n)
			data->color_min = n;
	}
	else
	{
		if ((unsigned int)n > data->color_max)
			data->color_max = n;
		if ((unsigned int)n < data->color_min)
			data->color_min = n;
	}
}

unsigned int	find_color(int pos, int pos_1, t_data *data)
{
	unsigned int	color;

	color = UINT_MAX / data->color_hold / 100 * ft_n_max(pos, pos_1);
	color += UINT_MAX / 3;
	color += (data->z * 100);
	if (data->col.color_n == UINT_MAX / 4)
	{
		color = data->col.color_n;
	}
	return (color);
}
