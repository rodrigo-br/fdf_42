#include "../ft_fdf.h"

void    read_size(t_data *data)
{
    int max;

    max = ft_n_max(data->y_lines, data->x_columns);
    data->zoom = 10;
    while ((1000 / max) < data->zoom)
        data->zoom -= 2;
    // data->start = 1;
    // data->start = (1000 / 2) - (1000 / data->zoom);
    // while ((data->start + (data->zoom * max)) > 1000)
    //     data->start -= 2;
}

int main (int *argc, char **argv)
{
    t_data  data;
    int     fd;

    (void)argc;
    data.x_axis = 10;
    data.y_axis = 10;
    data.z = 0;
    data.angle = 0.8;
    data.y_lines = -1;
    data.x_columns = 0;
    fd = open(argv[1], O_RDONLY);
    data.matrix_boladona = read_map(fd, argv[1], &data);
    read_size(&data);
    fdf(&data);
    return (0);
}
