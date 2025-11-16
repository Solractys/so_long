#include "../../includes/ft_printf/ft_printf.h"
#include "../../includes/map.h"

void   free_map(t_map *map)
{
    int i;

    if (!map)
        return ;
    i = 0;
    while (map->map[i])
    {
        free(map->map[i]);
        i++;
    }
    free(map->map);
    free(map);
}