#include "../ft_fdf.h"

int main (int *argc, char **argv)
{
    t_data  data;
    int     fd;
    int     x;
    int     y;

    (void)argc;
    x = 0;
    data.x_lines = -1;
    data.y_columns = 0;
    fd = open(argv[1], O_RDONLY);
    data.matrix_boladona = read_map(fd, argv[1], &data);
    while(x < data.x_lines)
    {
        y = 0;
        while (y < data.y_columns)
        {
            ft_printf("%3d", data.matrix_boladona[x][y]);
            y++;
        }
        free(data.matrix_boladona[x]);
        ft_printf("\n");
        x++;
    }
    free(data.matrix_boladona);
    return (0);
}
