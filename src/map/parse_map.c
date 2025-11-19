/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 23:06:30 by csilva-s          #+#    #+#             */
/*   Updated: 2025/11/18 23:06:30 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map.h"
#include "gnl/get_next_line.h"
#include "../../includes/so_long.h"
#include "../../includes/ft_printf/ft_printf.h"

int	count_lines(char *filename)
{
	int		fd;
	ssize_t	r;
	char	buffer[1024];
	int		lines;
	char	last;

	lines = 0;
	last = '\0';
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	r = read(fd, buffer, sizeof(buffer));
	while (r > 0)
	{
		last = handle_line_count(buffer, r, &lines);
		r = read(fd, buffer, sizeof(buffer));
	}
	if (r < 0)
		return (close(fd), -1);
	close(fd);
	if (last != '\n' && last != '\0')
		lines++;
	return (lines);
}

int	count_columns(char *filename)
{
	int		fd;
	ssize_t	r;
	char	c;
	int		cols;

	cols = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	r = read(fd, &c, 1);
	while (r > 0 && c != '\n')
	{
		if (c != '\r')
			cols++;
		r = read(fd, &c, 1);
	}
	if (r < 0)
		return (close(fd), -1);
	close(fd);
	return (cols);
}

static void	free_partial_map(char **map, int count)
{
	int	i;

	i = 0;
	while (i < count && map[i])
	{
		free(map[i]);
		i++;
	}
}

int	put_on_map(char **map, char *filename, int height)
{
	int	fd;
	int	result;
	int	lines_read;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	lines_read = 0;
	result = read_lines_into_map(map, fd, height);
	close(fd);
	if (!result)
	{
		while (map[lines_read])
			lines_read++;
		free_partial_map(map, lines_read);
		return (0);
	}
	return (1);
}

t_map	*read_map(char *filename)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->height = count_lines(filename);
	map->width = count_columns(filename);
	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (!map->map)
		return (free(map), NULL);
	if (!put_on_map(map->map, filename, map->height))
		return (free(map->map), free(map), NULL);
	count_info_map(map);
	return (map);
}
