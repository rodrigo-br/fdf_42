#include "../ft_fdf.h"

void    bresenham(t_data *data, t_bres bres)
{
    t_rgb   color;

    color.color_n = find_color(bres.z[0], bres.z[1], data);
    add_zoom(&bres, data->zoom);
    if (data->projection % 2 == 0)
    {
        rotate(&bres, data);
        add_3d(&bres, data);
    }
    add_position(&bres, data);
    add_steps(&bres);
    while ((int)(bres.x[0] - bres.x[1]) || (int)(bres.y[0] - bres.y[1]))
    {
        my_mlx_pixel_put(data, bres.x[0], bres.y[0], color.color_n);
        bres.x[0] += bres.delta_x;
        bres.y[0] += bres.delta_y;
    }
}

void    put_points(t_data *data)
{
    t_bres  bres;

    bres.y[0] = -1;
    while (++bres.y[0] < data->y_lines)
    {
        bres.x[0] = -1;
        while (++bres.x[0] < data->x_columns)
        {
            bres.x[1] = bres.x[0] + 1;
            bres.y[1] = bres.y[0];
            if (bres.x[0] < data->x_columns - 1)
            {
                bres.z[0] = data->matrix_boladona[(int)bres.y[0]][(int)bres.x[0]];
                bres.z[1] = data->matrix_boladona[(int)bres.y[1]][(int)bres.x[1]];
                bresenham(data, bres);
            }
            bres.y[1] = bres.y[0] + 1;
            bres.x[1] -= 1;
            if (bres.y[0] < data->y_lines - 1)
            {
                bres.z[0] = data->matrix_boladona[(int)bres.y[0]][(int)bres.x[0]];
                bres.z[1] = data->matrix_boladona[(int)bres.y[1]][(int)bres.x[1]];
                bresenham(data, bres);
            }
        }
    }
}
