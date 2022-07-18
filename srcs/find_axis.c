#include "../ft_fdf.h"

int **faz_matrix_boladona(int fd, char *arg_1, t_data *data)
{
    int     **matrix;
    char    **temp_matrix;
    char    *mapping;
    int     i;
    int     temp_i;

    i = 0;
    fd = open(arg_1, O_RDONLY);
    matrix = (int **)malloc(sizeof(int *) * data->y_lines);
    while (i < data->y_lines)
    {
        mapping = get_next_line(fd);
        temp_matrix = ft_split(mapping, ' ');
        free(mapping);
        temp_i = 0;
        matrix[i] = (int *)malloc(sizeof(int) * data->x_columns);
        while (temp_i < data->x_columns)
        {
            matrix[i][temp_i] = ft_atoi(temp_matrix[temp_i]);
            free(temp_matrix[temp_i]);
            temp_i++;
        }
        free(temp_matrix);
        i++;
    }
    mapping = get_next_line(fd);
    free(mapping);
    close(fd);
    return(matrix);
}

int **read_map(int fd, char *arg_1, t_data *data)
{
    char    *line;
    char    **matrix;
    int     i;

    i = 0;
    line = get_next_line(fd);
    if (line)
    {
        data->y_lines += 1;
        matrix = ft_split(line, ' ');
        while (matrix[i])
        {
            data->x_columns += 1;
            free(matrix[i]);
            i++;
        }
        free(line);
        free(matrix);
    }
    while (line && data->y_lines >= 0)
    {
        data->y_lines += 1;
        line = get_next_line(fd);
        free(line);
    }
    close(fd);
    return (faz_matrix_boladona(fd, arg_1, data));
}
