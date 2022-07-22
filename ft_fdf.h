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

/*-----------------------------------------------------------------\
|                   INCLUDES                                        |
\-----------------------------------------------------------------*/
# include "printf/ft_printf.h"
# include "buttons.h"
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>

/*-----------------------------------------------------------------\
|                   DEFINES                                        |
\-----------------------------------------------------------------*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE       4096
# endif
# define WIDTH              1280
# define HEIGHT             720
# define MENU_WIDTH         150

/*-----------------------------------------------------------------\
|                   STRUCTS                                         |
\-----------------------------------------------------------------*/
typedef struct	s_data
{
    int     projection;
    int     **matrix_boladona;
    int     x_axis;
    int     y_axis;
    double  angle;
    double  z;
	int		bits_per_pixel;
	int		line_length;
    int     x_columns;
    int     y_lines;
	int		endian;
    int     start;
    int     zoom;
	char	*addr;
    void    *menu;
	void	*mlx;
	void	*win;
	void	*img;
    double  gamma;
    double  alpha;
    double  beta;
}	t_data;

typedef struct s_bres
{
    float      delta_x;
    float      delta_y;
    float      x[3];
    float      y[3];
    int        z[3];
}   t_bres;

/*-----------------------------------------------------------------\
|                   FUNCTIONS                                       |
\-----------------------------------------------------------------*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int     **read_map(int fd, char *arg_1, t_data *data);
char	*get_next_line(int fd);
int     ft_n_max(int x, int y);
void    put_points(t_data *data);
int     fdf(t_data *data);
void    fill_data(t_data *data);

#endif