#include "../../includes/map.h"
#include "gnl/get_next_line.h"
#include "../../includes/so_long.h"
#include "../../includes/ft_printf/ft_printf.h"

int count_lines(char *filename)
{
    int fd;
    ssize_t r;
    char buffer[1024];
    int lines = 0;
    ssize_t total = 0;
    char last_char = '\0';

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (-1);
    while ((r = read(fd, buffer, sizeof(buffer))) > 0)
    {
        total += r;
        for (ssize_t i = 0; i < r; i++)
        {
            if (buffer[i] == '\n')
                lines++;
            last_char = buffer[i];
        }
    }
    if (r < 0)
    {
        close(fd);
        return (-1);
    }
    if (total > 0 && last_char != '\n')
        lines++;
    close(fd);
    return (lines);
}
int count_columns(char *filename)
{
    int fd;
    ssize_t r;
    char buffer[1];
    int columns = 0;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (-1);
    while ((r = read(fd, buffer, 1)) > 0)
    {
        if (buffer[0] == '\r')
            continue;
        if (buffer[0] == '\n')
            break;
        columns++;
    }
    if (r < 0)
    {
        close(fd);
        return (-1);
    }
    close(fd);
    return (columns);
}
int    put_on_map(char **map, char *filename, int height)
{
    int     fd;
    char    *line;
    int     i;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (0);
    i = 0;
    while (i < height && (line = get_next_line(fd)) != NULL)
    {
        int j = 0;
        while (line[j])
        {
            if (line[j] == '\n' || line[j] == '\r')
            {
                line[j] = '\0';
                break;
            }
            j++;
        }
        ft_printf("[put_on_map] read line %d len=%d: %s\n", i, (int)ft_strlen(line), line);
        map[i] = line;
        i++;
    }
    map[i] = NULL;
    close(fd);
    return (1);
}
t_map    *read_map(char *filename)
{
    t_map   *map;

    map = malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    map->height = count_lines(filename);
    map->width = count_columns(filename);
    map->map = malloc(sizeof(char *) * (map->height + 1));
    if (!map->map)
    {
        free(map);
        return (NULL);
    }
    if(!put_on_map(map->map, filename, map->height))
    {
        free(map->map);
        free(map);
        return (NULL);
    }
    count_info_map(map);
    return (map);
}