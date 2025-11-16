#include "../../includes/map.h"

void    count_info_map(t_map *map)
{
    int y;
    int x;

    y = 0;
    map->collectibles = 0;
    while (map->map[y])
    {
        x = 0;
        while (map->map[y][x])
        {
            if (map->map[y][x] == 'C')
                map->collectibles++;
            else if (map->map[y][x] == 'E')
            {
                map->exit_x = x;
                map->exit_y = y;
            }
            else if (map->map[y][x] == 'P')
            {
                map->player_x = x;
                map->player_y = y;
            }
            x++;
        }
        y++;
    }
}