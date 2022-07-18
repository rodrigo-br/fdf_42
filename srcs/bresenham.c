#include "../ft_fdf.h"
#include <stdio.h>

void    bresenham(t_data *data, t_bres bres, int color)
{
    int     steps;
    float   x_step;
    float   y_step;

    bres.x[0] *= data->zoom;
    bres.x[1] *= data->zoom;
    bres.y[0] *= data->zoom;
    bres.y[1] *= data->zoom;
    bres.delta_x = bres.x[1] - bres.x[0];
    bres.delta_y = bres.y[1] - bres.y[0];
    steps = (ft_n_max(ft_abs(bres.delta_x), ft_abs(bres.delta_y)));
    x_step = (float)bres.delta_x / (float)steps;
    y_step = (float)bres.delta_y / (float)steps;
    while (steps--)
    {
        my_mlx_pixel_put(data, bres.x[0], bres.y[0], color);
        bres.x[0] += x_step;
        bres.y[0] += y_step;
    }
}

int find_color(int pos)
{
    if (pos > 0)
        return (0xFF0000);
    else if (pos == 0)
        return (0xFFFFFF);
    else
        return (0x0000FF);
}

void    put_points(t_data *data)
{
    int     color;
    t_bres  bres;

    bres.x[0] = 0;
    while (bres.x[0] < data->x_lines)
    {
        bres.y[0] = 0;
        while (bres.y[0] < data->y_columns)
        {

            color = find_color(data->matrix_boladona[(int)bres.x[0]][(int)bres.y[0]]);
            bres.x[1] = bres.x[0] + 1;
            bres.y[1] = bres.y[0];
            if (bres.x[0] < data->x_lines - 1)
                bresenham(data, bres, color);
            bres.y[1] = bres.y[0] + 1;
            bres.x[1] -= 1;
            if (bres.y[0] < data->y_columns - 1)
                bresenham(data, bres, color);
            bres.y[0]++;
        }
        bres.x[0]++;
    }
}
