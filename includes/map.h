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
