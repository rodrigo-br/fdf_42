#include "../ft_fdf.h"

unsigned int find_color(int pos, int pos_1, t_data *data)
{
    unsigned int color;

    color = UINT_MAX / data->color_hold / 100 * ft_n_max(pos, pos_1);
    color += UINT_MAX / 3;
    color += (data->z * 100);
    if (data->col.color_n == UINT_MAX / 4)
    {
        color = data->col.color_n;
    }
    return (color);
}

void    add_3d(t_bres *bres, t_data *data)
{
    float       temp_x;
    float       temp_y;

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

//The index 2 are being used to hold a temporary value
void    rotate(t_bres *bres, t_data *data)
{
	bres->y[2] = bres->y[0];
	bres->z[2] = bres->z[0] * data->z;
	bres->y[0] = bres->y[2] * cos(data->alpha) - bres->z[2] * sin(data->alpha);
	bres->z[0] = bres->y[2] * sin(data->alpha) + bres->z[2] * cos(data->alpha);
    bres->y[2] = bres->y[1];
	bres->z[2] = bres->z[1] * data->z;
	bres->y[1] = bres->y[2] * cos(data->alpha) - bres->z[2] * sin(data->alpha);
	bres->z[1] = bres->y[2] * sin(data->alpha) + bres->z[2] * cos(data->alpha);
    bres->x[2] = bres->x[0];
	bres->z[2] = bres->z[0] * data->z;
	bres->x[0] = bres->x[2] * cos(data->beta) + bres->z[2] * sin(data->beta);
	bres->z[0] = -bres->x[2] * sin(data->beta) + bres->z[2] * cos(data->beta);
    bres->x[2] = bres->x[1];
	bres->z[2] = bres->z[1] * data->z;
	bres->x[1] = bres->x[2] * cos(data->beta) + bres->z[2] * sin(data->beta);
	bres->z[1] = -bres->x[2] * sin(data->beta) + bres->z[2] * cos(data->beta);
	bres->x[2] = bres->x[0];
	bres->y[2] = bres->y[0];
	bres->x[0] = bres->x[2] * cos(data->gamma) - bres->y[2] * sin(data->gamma);
	bres->y[0] = bres->x[2] * sin(data->gamma) + bres->y[2] * cos(data->gamma);
    bres->x[2] = bres->x[1];
	bres->y[2] = bres->y[1];
	bres->x[1] = bres->x[2] * cos(data->gamma) - bres->y[2] * sin(data->gamma);
	bres->y[1] = bres->x[2] * sin(data->gamma) + bres->y[2] * cos(data->gamma);
}

void    bresenham(t_data *data, t_bres bres)
{
    int     steps;
    t_rgb   color;

    color.color_n = find_color(bres.z[0], bres.z[1], data);
    bres.x[0] *= data->zoom;
    bres.x[1] *= data->zoom;
    bres.y[0] *= data->zoom;
    bres.y[1] *= data->zoom;
    if (data->projection % 2 == 0)
    {
        rotate(&bres, data);
        add_3d(&bres, data);
    }
    bres.x[0] += data->x_axis + data->start;
    bres.x[1] += data->x_axis + data->start;
    bres.y[0] += data->y_axis + data->start;
    bres.y[1] += data->y_axis + data->start;
    bres.delta_x = bres.x[1] - bres.x[0];
    bres.delta_y = bres.y[1] - bres.y[0];
    steps = (ft_n_max(fabs(bres.delta_x), fabs(bres.delta_y)));
    bres.delta_x /= steps;
    bres.delta_y /= steps;
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
