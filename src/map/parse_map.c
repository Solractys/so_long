#include "../../includes/map.h"
#include "gnl/get_next_line.h"
#include "../../includes/ft_printf/ft_printf.h"

char    *read_map(char *filename, t_game *game)
{
    int fd;
    char *line;
    t_map map;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (NULL);
    while ((line = get_next_line(fd)) != NULL)
    {

    }
}
