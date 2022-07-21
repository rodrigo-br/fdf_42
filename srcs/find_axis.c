#include "../ft_fdf.h"

int     **clean(char **temp_matrix, int **matrix, int count, int fd)
{
    int     i;
    char    *gnl;

    i = 0;
    while (temp_matrix[i])
    {
        free(temp_matrix[i]);
        i++;
    }
    free(temp_matrix);
    i = 0;
    while (i < count)
    {
        free(matrix[i]);
        i++;
    }
    free(matrix);
    while (1)
    {
        gnl = get_next_line(fd);
        free(gnl);
        if (!gnl)
            break;
    }
    return (NULL);
}

int    testmap(char **matrix)
{
    int i;

    i = 0;
    while(matrix[i])
        i++;
    return (i);
}
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
        if (testmap(temp_matrix) != data->x_columns)
            return (clean(temp_matrix, matrix, i, fd));
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
