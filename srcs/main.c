#include "../ft_fdf.h"

int main (int *argc, char **argv)
{
    int     **matrix_boladona;
    int     fd;
    int     x;
    int     y;
    int     x_lines;
    int     y_columns;

    (void)argc;
    x = 0;
    x_lines = -1;
    y_columns = 0;
    fd = open(argv[1], O_RDONLY);
    matrix_boladona = read_map(fd, argv[1], &x_lines, &y_columns);
    while(x < x_lines)
    {
        y = 0;
        while (y < y_columns)
        {
            ft_printf("%3d", matrix_boladona[x][y]);
            y++;
        }
        free(matrix_boladona[x]);
        ft_printf("\n");
        x++;
    }
    free(matrix_boladona);
    return (0);
}
