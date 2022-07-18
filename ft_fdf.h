/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 22:57:39 by ralves-b          #+#    #+#             */
/*   Updated: 2022/07/14 23:40:14 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "printf/ft_printf.h"
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>

# define ESC 65307

typedef struct	s_data
{
    int     **matrix_boladona;
	int		bits_per_pixel;
	int		line_length;
    int     y_columns;
    int     x_lines;
	int		endian;
    int     start;
    int     zoom;
	char	*addr;
	void	*mlx;
	void	*win;
	void	*img;
}	t_data;

typedef struct s_bres
{
    double     x[2];
    double     y[2];
    int     delta_x;
    int     delta_y;
    int     z;
}   t_bres;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int     **read_map(int fd, char *arg_1, t_data *data);
char	*get_next_line(int fd);
int     ft_n_max(int x, int y);
void    put_points(t_data *data);
int     fdf(t_data *data);
int     ft_abs(int n);

#endif