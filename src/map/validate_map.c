#include "../includes/map.h"
#include "../includes/ft_printf/ft_printf.h"

int validate_map_characters(t_map *map)
{
    int y;
    int x;

    y = 0;
    while (map->map[y])
    {
        x = 0;
        while (map->map[y][x])
        {
            if (map->map[y][x] != '0' && map->map[y][x] != '1' &&
                map->map[y][x] != 'C' && map->map[y][x] != 'E' &&
                map->map[y][x] != 'P')
            {
                return (0);
            }
            x++;
        }
        y++;
    }
    return (1);
}
int validate_line_lengths(t_map *map)
{
    int y;
    size_t expected_length;

    y = 0;
    if (map->height == 0)
        return (0);
    expected_length = map->width;
    y = 0;
    while (map->map[y])
    {
        if (ft_strlen(map->map[y]) != expected_length)
            return (0);
        y++;
    }
    return (1);
}
int validate_map_walls(t_map *map)
{
    int y;
    int x;

    y = 0;
    x = 0;
    while (map->map[0][x])
    {
        if (map->map[0][x] != '1' || map->map[map->height - 1][x] != '1')
            return (0);
        x++;
    }
    while (y < map->height)
    {
        if (map->map[y][0] != '1' || map->map[y][map->width - 1] != '1')
            return (0);
        y++;
    }
    return (1);
}
int validate_map(t_map *map)
{
    if (!validate_map_characters(map))
    {
        ft_printf("Validation failed: invalid characters\n");
        return (0);
    }
    if (!validate_line_lengths(map))
    {
        ft_printf("Validation failed: line length mismatch\n");
        int y = 0;
        while (map->map[y])
        {
            ft_printf("Line %d length=%d: %s\n", y, (int)ft_strlen(map->map[y]), map->map[y]);
            y++;
        }
        ft_printf("Expected width=%d, height=%d\n", map->width, map->height);
        return (0);
    }
    if (!validate_map_walls(map))
    {
        ft_printf("Validation failed: walls\n");
        int x;
        for (x = 0; x < map->width; x++)
        {
            if (map->map[0][x] != '1')
                ft_printf("Top border at x=%d is '%c'\n", x, map->map[0][x]);
            if (map->map[map->height - 1][x] != '1')
                ft_printf("Bottom border at x=%d is '%c'\n", x, map->map[map->height - 1][x]);
        }
        int y;
        for (y = 0; y < map->height; y++)
        {
            if (map->map[y][0] != '1')
                ft_printf("Left border at y=%d is '%c'\n", y, map->map[y][0]);
            if (map->map[y][map->width - 1] != '1')
                ft_printf("Right border at y=%d is '%c'\n", y, map->map[y][map->width - 1]);
        }
       return (0);
    }
	if (!is_valid_path(map))
	{
		ft_printf("Validation failed: invalid path\n");
		return (0);
	}
    return (1);
}
