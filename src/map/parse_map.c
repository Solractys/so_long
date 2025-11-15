#include "../../includes/map.h"
#include "gnl/get_next_line.h"
#include "../../includes/so_long.h"
#include "../../includes/ft_printf/ft_printf.h"

int count_lines(char *filename)
{
    int fd;
    int lines;
    char *line;

    lines = 0;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (-1);
    while ((line = get_next_line(fd)) != NULL)
    {
        lines++;
        free(line);
    }
    close(fd);
    return (lines);
}
int count_columns(char *filename)
{
    int fd;
    int columns;
    char *line;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (-1);
    line = get_next_line(fd);
    if (line == NULL)
    {
        close(fd);
        return (0);
    }
    columns = 0;
    while (line[columns] && line[columns] != '\n')
        columns++;
    free(line);
    close(fd);
    return (columns);
}
t_map    *read_map(char *filename)
{
    int     fd;
    t_map   *map;
    char    *line;
    int     i;

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
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        free(map->map);
        free(map);
        return (NULL);
    }
    i = 0;
    while (i < map->height && (line = get_next_line(fd)) != NULL)
    {
        map->map[i] = line;
        i++;
    }
    map->map[i] = NULL;
    close(fd);
    return (map);
}