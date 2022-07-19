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
# include <stdio.h>
# include <limits.h>

# define ESC        65307
# define LEFT       65361
# define UP         65362
# define RIGHT      65363
# define DOWN       65364
# define W_KEY      119
# define S_KEY      115
# define E_KEY      101
# define Q_KEY      113
# define PLUS_KEY   65451
# define MINUS_KEY  65453
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# define WIDTH      1420
# define HEIGHT     1024
# endif

typedef struct	s_data
{
    int     **matrix_boladona;
    int     x_axis;
    int     y_axis;
    double  angle;
    int     z;
	int		bits_per_pixel;
	int		line_length;
    int     x_columns;
    int     y_lines;
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
    float      delta_x;
    float      delta_y;
    float      x[2];
    float      y[2];
    int        z[2];
}   t_bres;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int     **read_map(int fd, char *arg_1, t_data *data);
char	*get_next_line(int fd);
int     ft_n_max(int x, int y);
void    put_points(t_data *data);
int     fdf(t_data *data);
int     ft_abs(int n);

#endif