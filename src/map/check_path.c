/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 22:58:25 by csilva-s          #+#    #+#             */
/*   Updated: 2025/11/18 22:58:30 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map.h"
#include "../../includes/ft_printf/ft_printf.h"

void	dfs(t_map *map, int x, int y)
{
	if (x < 0 || x >= map->height || y < 0 || y >= map->width)
		return ;
	if (map->map[x][y] == '1' || map->map[x][y] == 'V')
		return ;
	map->map[x][y] = 'V';
	dfs(map, x + 1, y);
	dfs(map, x - 1, y);
	dfs(map, x, y + 1);
	dfs(map, x, y - 1);
}

char	**copy_map(t_map *map)
{
	int		i;
	char	**map_copy;

	map_copy = (char **)ft_calloc(map->height + 1, sizeof(char *));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		map_copy[i] = ft_strdup(map->map[i]);
		if (!map_copy[i])
		{
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	return (map_copy);
}

static int	init_copy_struct(t_map *map, t_map **map_copy)
{
	*map_copy = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!*map_copy)
		return (0);
	(*map_copy)->map = copy_map(map);
	if (!(*map_copy)->map)
	{
		free(*map_copy);
		return (0);
	}
	(*map_copy)->height = map->height;
	(*map_copy)->width = map->width;
	return (1);
}

static int	check_results(t_map *map, t_map *map_copy)
{
	int	collectibles_left;
	int	exit_found;

	exit_found = 0;
	count_info_map(map_copy);
	collectibles_left = map_copy->collectibles;
	if (map_copy->map[map->exit_y][map->exit_x] == 'V')
		exit_found = 1;
	if (collectibles_left != 0 || exit_found == 0)
		return (0);
	return (1);
}

int	is_valid_path(t_map *map)
{
	t_map	*map_copy;
	int		result;

	if (!init_copy_struct(map, &map_copy))
		return (0);
	dfs(map_copy, map->player_x, map->player_y);
	result = check_results(map, map_copy);
	free_map(map_copy);
	return (result);
}
