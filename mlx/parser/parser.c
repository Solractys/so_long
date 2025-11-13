#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
typedef struct s_map
{
    int height;
    int width;
    int items;
    int exits;
}   t_map;
int main(void)
{
    t_map map;
    int fd = open("map.ber", O_RDWR);
    char *line = get_next_line(fd);
    int x = 0;
    
    free(line);
    close(fd);
    return (0);
}

