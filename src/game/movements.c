/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 00:35:58 by csilva-s          #+#    #+#             */
/*   Updated: 2025/11/19 00:35:58 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"
#include "../../includes/so_long.h"
#include "../../includes/map.h"
#include "../../includes/render.h"
#include "../../includes/ft_printf/ft_printf.h"

int	is_move_valid(t_map *map, int x, int y)
{
	char	tile;

	tile = map->map[y][x];
	if (tile == '1')
		return (0);
	if (tile == 'E' && map->collectibles > 0)
		return (0);
	if (tile == 'E' && map->collectibles == 0)
		return (2);
	return (1);
}

void	update_player_position(t_map *map, int new_x, int new_y)
{
	if (map->map[new_y][new_x] == 'C')
		map->collectibles--;
	map->map[map->player_y][map->player_x] = '0';
	map->map[new_y][new_x] = 'P';
	map->player_x = new_x;
	map->player_y = new_y;
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_y = game->map->player_y + dy;
	new_x = game->map->player_x + dx;
	if (is_move_valid(game->map, new_x, new_y))
	{
		if (is_move_valid(game->map, new_x, new_y) == 2)
		{
			game_win(game);
			return ;
		}
		update_player_position(game->map, new_x, new_y);
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
		render_map(game);
	}
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_W)
	{
		game->player_direction = 0;
		move_player(game, 0, -1);
	}
	else if (keycode == KEY_S)
	{
		game->player_direction = 1;
		move_player(game, 0, 1);
	}
	else if (keycode == KEY_A)
	{
		game->player_direction = 2;
		move_player(game, -1, 0);
	}
	else if (keycode == KEY_D)
	{
		game->player_direction = 3;
		move_player(game, 1, 0);
	}
	else if (keycode == KEY_ESC)
		exit_game(game);
	return (0);
}
