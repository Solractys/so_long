#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "map.h"

typedef struct s_game
{
    void *mlx;
    void *win;
    t_map *map;
    void *wall_img;
    void *floor_img;
    void *player_img;
    void *exit_img;
    void *collectible_img;
} t_game;
