#include "../includes/ft_printf/ft_printf.h"
#include <math.h>

int ft_random_nums(int min, int max)
{
    double scaled;
    int random_num;

    scaled = (double)rand() / RAND_MAX;
    random_num = (int)(scaled * (max - min + 1)) + min;
    return (random_num);

}