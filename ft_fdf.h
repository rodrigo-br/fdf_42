/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_fdf.h										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ralves-b <ralves-b@student.42sp.org.br>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/07/14 22:57:39 by ralves-b		  #+#	#+#			 */
/*   Updated: 2022/07/22 21:39:14 by ralves-b		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

/*-----------------------------------------------------------------\
|				   INCLUDES										|
\-----------------------------------------------------------------*/
# include "printf/ft_printf.h"
# include "buttons.h"
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>

# define WIDTH 1280
# define HEIGHT 720
# define MENU_WIDTH 150
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef union u_rgb
{
	unsigned int	color_n;
	char			rgb[4];
}					t_rgb;

typedef struct s_data
{
	int				projection;
	int				**matrix_boladona;
	int				x_axis;
	int				y_axis;
	double			angle;
	double			z;
	int				bits_per_pixel;
	int				line_length;
	int				x_columns;
	int				y_lines;
	int				endian;
	int				start;
	int				zoom;
	char			*addr;
	void			*menu;
	void			*mlx;
	void			*win;
	void			*img;
	double			gamma;
	double			alpha;
	double			beta;
	unsigned int	color_max;
	unsigned int	color_min;
	unsigned int	color_hold;
	t_rgb			col;
}					t_data;

typedef struct s_bres
{
	float	delta_x;
	float	delta_y;
	float	x[3];
	float	y[3];
	int		z[3];
}			t_bres;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				**read_map(int fd, char *arg_1, t_data *data);
char			*get_next_line(int fd);
int				ft_n_max(int x, int y);
void			put_points(t_data *data);
int				fdf(t_data *data);
void			fill_data(t_data *data);
unsigned int	find_color(int pos, int pos_1, t_data *data);
void			check_color_max(int n, t_data *data);
int				key_hook(int keycode, t_data *mlx);
int				mouse_hook(int keycode, int x, int y, t_data *mlx);
int				end_program(t_data *mlx);
int				rerender(t_data *data);
int				exit_error(int erro);
void			rotate(t_bres *bres, t_data *data);
void			add_3d(t_bres *bres, t_data *data);
void			add_steps(t_bres *bres);
void			add_position(t_bres *bres, t_data *data);
void			add_zoom(t_bres *bres, int zoom);

#endif