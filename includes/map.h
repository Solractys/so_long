#ifndef MAP_H
#define MAP_H

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

t_map   *read_map(char *filename);
void	print_wall_errors(t_map *map);
void    clean_line(char *line);
void    dfs(t_map *map, int x, int y);
void    count_info_map(t_map *map);
void    free_map(t_map *map);
char    **copy_map(t_map *map);
int handle_line_count(char *buffer, ssize_t r, int *lines);
int is_valid_path(t_map *map);
int	read_lines_into_map(char **map, int fd, int height);
int count_lines(char *filename);
int count_columns(char *filename);
int put_on_map(char **map, char *filename, int height);
int validate_map_characters(t_map *map);
int validate_line_lengths(t_map *map);
int validate_map(t_map *map);
int validate_map_walls(t_map *map);

#endif
