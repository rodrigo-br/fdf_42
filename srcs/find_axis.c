#include "../ft_fdf.h"

void    faz_matrix_boladona(int fd, char *arg_1, int y_columns, int x_lines)
{
    int     **matrix;
    char    **temp_matrix;
    char    *mapping;
    int     i;
    int     temp_i;

    i = 0;
    fd = open(arg_1, O_RDONLY);
    matrix = (int **)malloc(sizeof(int *) * x_lines);
    while (i < x_lines)
    {
        mapping = get_next_line(fd);
        temp_matrix = ft_split(mapping, ' ');
        temp_i = 0;
        matrix[i] = (int *)malloc(sizeof(int) * y_columns);
        while (temp_i < y_columns)
        {
            matrix[i][temp_i] = ft_atoi(temp_matrix[temp_i]);
            ft_printf("%3d", matrix[i][temp_i]);
            temp_i++;
        }
        free(temp_matrix);
        ft_printf("\n");
        i++;
    }
    close(fd);
}

int read_map(int fd, char *arg_1)
{
    int     count_lines;
    char    *line;
    int     count_columns;
    char    **matrix;

    count_lines = -1;
    count_columns = 0;
    line = get_next_line(fd);
    if (line)
    {
        count_lines++;
        matrix = ft_split(line, ' ');
        while (*matrix++)
            count_columns++;
        free(line);
    }
    while (line && count_lines >= 0)
    {
        count_lines++;
        line = get_next_line(fd);
        free(line);
    }
    faz_matrix_boladona(fd, arg_1, count_columns, count_lines);
    close(fd);
    return (0);
}
