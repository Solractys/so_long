#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx.h"
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
    int moves;
} t_game;

#endif
