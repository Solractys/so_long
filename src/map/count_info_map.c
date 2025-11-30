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

static void	handle_cell(t_map *map, int y, int x)
{
	if (map->map[y][x] == 'C')
		map->collectibles++;
	else if (map->map[y][x] == 'E')
	{
		map->exit_x = x;
		map->exit_y = y;
	}
	else if (map->map[y][x] == 'P')
	{
		map->player_x = x;
		map->player_y = y;
	}
}

void	count_info_map(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	map->collectibles = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			handle_cell(map, y, x);
			x++;
		}
		y++;
	}
}
