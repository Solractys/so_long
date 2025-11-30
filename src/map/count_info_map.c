/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_info_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:01:20 by csilva-s          #+#    #+#             */
/*   Updated: 2025/11/18 17:01:20 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map.h"

static void	handle_cell(t_map *map, int y, int x, int *player_count, int *exit_count)
{
	if (map->map[y][x] == 'C')
		map->collectibles++;
	else if (map->map[y][x] == 'E')
	{
		map->exit_x = x;
		map->exit_y = y;
		(*exit_count)++;
	}
	else if (map->map[y][x] == 'P')
	{
		map->player_x = x;
		map->player_y = y;
		(*player_count)++;
	}
}

int	count_info_map(t_map *map)
{
	int	y;
	int	x;
	int	player_count;
	int	exit_count;

	y = 0;
	map->collectibles = 0;
	player_count = 0;
	exit_count = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			handle_cell(map, y, x, &player_count, &exit_count);
			x++;
		}
		y++;
	}
	if (player_count != 1 || exit_count != 1 || map->collectibles < 1)
		return (0);
	return (1);
}
