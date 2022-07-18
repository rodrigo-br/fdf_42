#include "../ft_fdf.h"
#include <stdio.h>

void    add_3d(t_bres *bres)
{
    float   temp_x;
    float   temp_y;

    temp_x = (bres->x[0] - bres->y[0]) * cos(0.8);
    temp_y = (bres->x[0] + bres->y[0]) * sin(0.8) - bres->z[0];
    bres->x[0] = temp_x + 300;
    bres->y[0] = temp_y + 300;
    temp_x = (bres->x[1] - bres->y[1]) * cos(0.8);
    temp_y = (bres->x[1] + bres->y[1]) * sin(0.8) - bres->z[1];
    bres->x[1] = temp_x + 300;
    bres->y[1] = temp_y + 300;
}

int find_color(int pos, int pos_1)
{
    if (pos > 0 || pos_1 > 0)
        return (0xFF0000);
    else if (pos < 0 || pos_1 < 0)
        return (0x0000FF);
    else
        return (0xFFFFFF);
}

void    bresenham(t_data *data, t_bres bres)
{
    int     steps;
    int     color;

    color = find_color(bres.z[0], bres.z[1]);
    bres.x[0] *= data->zoom;
    bres.x[1] *= data->zoom;
    bres.y[0] *= data->zoom;
    bres.y[1] *= data->zoom;
    add_3d(&bres);
    bres.delta_x = bres.x[1] - bres.x[0];
    bres.delta_y = bres.y[1] - bres.y[0];
    steps = (ft_n_max(fabs(bres.delta_x), fabs(bres.delta_y)));
    bres.delta_x /= steps;
    bres.delta_y /= steps;
    while ((int)(bres.x[0] - bres.x[1]) || (int)(bres.y[0] - bres.y[1]))
    {
        my_mlx_pixel_put(data, bres.x[0], bres.y[0], color);
        bres.x[0] += bres.delta_x;
        bres.y[0] += bres.delta_y;
    }
}



void    put_points(t_data *data)
{
    t_bres  bres;

    bres.y[0] = 0;
    while (bres.y[0] < data->y_lines)
    {
        bres.x[0] = 0;
        while (bres.x[0] < data->x_columns)
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
            bres.x[0]++;
        }
        bres.y[0]++;
    }
}
