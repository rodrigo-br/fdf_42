#include "../ft_fdf.h"

static int  exit_error(int erro)
{
    if (erro == 1)
        ft_printf("Número de argumentos inválido.\n");
    else if (erro == 2)
        ft_printf("Arquivo inválido.\n");
    else
        ft_printf("Mapa inválido.\n");
    return (-1);
}
void    read_size(t_data *data)
{
    int max;

    max = ft_n_max(data->y_lines, data->x_columns);
    data->zoom = 10;
    data->start = 10;
    // data->start = (1000 / 2) - (1000 / data->zoom);
    // while ((data->start + (data->zoom * max)) > 1000)
    //     data->start -= 2;
}

int main (int argc, char **argv)
{
    t_data  data;
    int     fd;

    if (argc != 2)
        return (exit_error(1));
    data.x_axis = 10;
    data.y_axis = 10;
    data.z = 1;
    data.angle = 0.8;
    data.y_lines = -1;
    data.x_columns = 0;
    data.projection = 0;
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return (exit_error(2));
    data.matrix_boladona = read_map(fd, argv[1], &data);
    if (!data.matrix_boladona)
        return (exit_error(3));
    read_size(&data);
    fdf(&data);
    return (0);
}
