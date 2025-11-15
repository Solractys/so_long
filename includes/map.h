#include <unistd.h>

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

#endif