/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:33:52 by csilva-s          #+#    #+#             */
/*   Updated: 2025/11/19 01:33:52 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "so_long.h"

# define KEY_W      119
# define KEY_A      97
# define KEY_S      115
# define KEY_D      100
# define KEY_ESC    65307

int		handle_keypress(int keycode, t_game *game);
int		is_move_valid(t_map *map, int x, int y);
int		exit_game(t_game *game);
void	game_init(t_game *game, t_map *map);
void	move_player(t_game *game, int dx, int dy);
void	update_player_position(t_map *map, int new_x, int new_y);
void	game_win(t_game *game);

#endif
