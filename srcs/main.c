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

void    fill_data(t_data *data)
{
    int max;

    max = ft_n_max(data->y_lines, data->x_columns);
    data->zoom = 15 - ((max / 10) * 2);
    if (data->zoom < 2)
        data->zoom = 2;
    data->x_axis = ((WIDTH - MENU_WIDTH) / 2);
    data->y_axis = (HEIGHT / 2) - (data->y_lines * data->zoom / 2);
    data->z = 1;
    data->angle = 0.8;
    data->projection = 0;
    data->start = 10;
    data->gamma = 0;
    data->alpha = 0;
    data->beta = 0;
    data->col.color_n = 0;
}

int main (int argc, char **argv)
{
    t_data  data;
    int     fd;

    if (argc != 2)
        return (exit_error(1));
    data.y_lines = -1;
    data.x_columns = 0;
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return (exit_error(2));
    data.color_max = 0;
    data.color_min = UINT_MAX;
    data.color_hold = 0;
    data.matrix_boladona = read_map(fd, argv[1], &data);
    if (!data.matrix_boladona)
        return (exit_error(3));
    fill_data(&data);
    fdf(&data);
    return (0);
}
