/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 00:31:56 by csilva-s          #+#    #+#             */
/*   Updated: 2025/11/19 00:31:56 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/game.h"
#include "../includes/ft_printf/ft_printf.h"

void	game_win(t_game *game)
{
	ft_printf("------------------------------\n");
	ft_printf("Congratulations! You've won the game!\n");
	ft_printf("Total Moves: %d\n", game->moves);
	ft_printf("------------------------------\n");
	exit_game(game);
}
