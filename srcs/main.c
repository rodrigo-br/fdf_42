#include "../ft_fdf.h"

void    read_size(t_data *data)
{
    int max;

    max = ft_n_max(data->x_lines, data->y_columns);
    data->zoom = 10;
    while ((1000 / max) < data->zoom)
        data->zoom -= 2;
    data->start = 1;
    // data->start = (1000 / 2) - (1000 / data->zoom);
    // while ((data->start + (data->zoom * max)) > 1000)
    //     data->start -= 2;
}

int main (int *argc, char **argv)
{
    t_data  data;
    int     fd;

    (void)argc;
    data.x_lines = -1;
    data.y_columns = 0;
    fd = open(argv[1], O_RDONLY);
    data.matrix_boladona = read_map(fd, argv[1], &data);
    read_size(&data);
    fdf(&data);
    return (0);
}
