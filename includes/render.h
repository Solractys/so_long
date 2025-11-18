#ifndef RENDER_H
#define RENDER_H

#include "so_long.h"
#include "../minilibx/mlx.h"

void render_map(t_game *game);
void load_images(t_game *game);
void draw_tile(t_game *game, void *mlx, void *win, int x, int y);
void destroy_images(t_game *game);

#endif