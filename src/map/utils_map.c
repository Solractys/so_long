/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 23:17:14 by csilva-s          #+#    #+#             */
/*   Updated: 2025/11/18 23:17:19 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map.h"
#include "../../includes/ft_printf/ft_printf.h"
#include "./gnl/get_next_line.h"

int	handle_line_count(char *buffer, ssize_t r, int *lines)
{
	ssize_t	i;

	i = 0;
	while (i < r)
	{
		if (buffer[i] == '\n')
			(*lines)++;
		i++;
	}
	return (buffer[r - 1]);
}

void	print_wall_errors(t_map *map)
{
	int		x;
	int		y;

	x = 0;
	while (x < map->width)
	{
		if (map->map[0][x] != '1')
			ft_printf("Top border at x=%d is '%c'\n",
				x, map->map[0][x]);
		if (map->map[map->height - 1][x] != '1')
			ft_printf("Bottom border at x=%d is '%c'\n",
				x, map->map[map->height - 1][x]);
		x++;
	}
	y = 0;
	while (y < map->height)
	{
		if (map->map[y][0] != '1')
			ft_printf("Left border at y=%d is '%c'\n",
				y, map->map[y][0]);
		if (map->map[y][map->width - 1] != '1')
			ft_printf("Right border at y=%d is '%c'\n",
				y, map->map[y][map->width - 1]);
		y++;
	}
}

void	clean_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n' || line[i] == '\r')
		{
			line[i] = '\0';
			return ;
		}
		i++;
	}
}

int	read_lines_into_map(char **map, int fd, int height)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (i < height && line)
	{
		clean_line(line);
		map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	if (i < height && line == NULL)
		return (0);
	return (1);
}
