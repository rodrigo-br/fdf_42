#include "../ft_fdf.h"

int main (int *argc, char **argv)
{
    int fd;

    (void)argc;
    fd = open(argv[1], O_RDONLY);
    read_map(fd, argv[1]);
    return (0);
}
