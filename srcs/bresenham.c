#include "../ft_fdf.h"

// void    bresenham(t_data *data)
// {
    
// }

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
    int     i_x;
    int     i_y;
    int     color;

    i_x = 0;
    while (i_x < data->x_lines)
    {
        i_y = 0;
        while (i_y < data->y_columns)
        {
            color = find_color(data->matrix_boladona[i_x][i_y]);
            my_mlx_pixel_put(data,
            (i_x + data->start) * data->zoom,
            (i_y + data->start) * data->zoom,
            color);
            i_y++;
        }
        i_x++;
    }
}