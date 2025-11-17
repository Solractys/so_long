#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_map
{
    char **map;
    int width;
    int height;
    int player_x;
    int player_y;
    int exit_x;
    int exit_y;
    int collectibles;
    int walls;
    int spaces;
} t_map;

#ifndef MAP_H
#define MAP_H


t_map    *read_map(char *filename);
int     count_lines(char *filename);
int     count_columns(char *filename);
void    free_map(t_map *map);
int     validate_map(t_map *map);
int     validate_map_characters(t_map *map);
int     validate_line_lengths(t_map *map);
int     validate_map_walls(t_map *map);
int     put_on_map(char **map, char *filename, int height);
void    count_info_map(t_map *map);
int     is_valid_path(t_map *map);
char   **copy_map(t_map *map);
void    dfs(t_map *map, int x, int y);

#endif
