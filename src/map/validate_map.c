/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 23:11:41 by csilva-s          #+#    #+#             */
/*   Updated: 2025/11/30 15:31:39 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../includes/ft_printf/ft_printf.h"

static void	print_line_lengths(t_map *map)
{
	int		y;
	size_t	len;

	y = 0;
	while (map->map[y])
	{
		len = ft_strlen(map->map[y]);
		ft_printf("Line %d length=%d: %s\n", y, (int)len, map->map[y]);
		y++;
	}
	ft_printf("Expected width=%d, height=%d\n", map->width, map->height);
}

int	validate_map_characters(t_map *map)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			c = map->map[y][x];
			if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	validate_line_lengths(t_map *map)
{
	int		y;
	size_t	expected_length;

	if (map->height == 0)
		return (0);
	expected_length = map->width;
	y = 0;
	while (map->map[y])
	{
		if (ft_strlen(map->map[y]) != expected_length)
			return (0);
		y++;
	}
	return (1);
}

int	validate_map_walls(t_map *map)
{
	int		y;
	int		x;

	x = 0;
	while (map->map[0][x])
	{
		if (map->map[0][x] != '1' ||
			map->map[map->height - 1][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (y < map->height)
	{
		if (map->map[y][0] != '1' ||
			map->map[y][map->width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	validate_map(t_map *map)
{
	if (!count_info_map(map))
	{
		ft_printf("Validation failed: invalid number of elements\n");
		return (0);
	}
	if (!validate_map_characters(map))
	{
		ft_printf("Validation failed: invalid characters\n");
		return (0);
	}
	if (!validate_line_lengths(map))
	{
		ft_printf("Validation failed: line length mismatch\n");
		print_line_lengths(map);
		return (0);
	}
	if (!validate_map_walls(map))
	{
		ft_printf("Validation failed: walls\n");
		print_wall_errors(map);
		return (0);
	}
	if (!is_valid_path(map))
	{
		ft_printf("Validation failed: invalid path\n");
		return (0);
	}
	return (1);
}
