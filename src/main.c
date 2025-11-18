/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:50:14 by csilva-s          #+#    #+#             */
/*   Updated: 2025/11/17 12:50:14 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../includes/ft_printf/ft_printf.h"
#include "../includes/map.h"
#include "../includes/so_long.h"
#include "../includes/render.h"

int check_file_extension_ber(const char *filename)
{
	size_t len;

	len = 0;
	while (filename[len] != '\0')
		len++;
	if (len < 4)
		return (0);
	return (filename[len - 4] == '.' &&
			filename[len - 3] == 'b' &&
			filename[len - 2] == 'e' &&
			filename[len - 1] == 'r');
}

int main(int argc, char **argv)
{
	t_game *game;
	t_map *map;
	if (argc != 2)
	{
		ft_printf("Usage: %s <map_file.ber>\n", argv[0]);
		return (1);
	}
	if (!check_file_extension_ber(argv[1]))
	{
		ft_printf("Error: Invalid file extension. Expected .ber\n");
		return (1);
	}
	game = malloc(sizeof(t_game));
	map = read_map(argv[1]);
	if (!validate_map(map))
	{
		ft_printf("Error: Invalid map structure.\n");
		return (1);
	}
	game->map = map;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, map->width * 32, map->height * 32, "So Long Game");
	render_map(game);
	free_map(map);
	mlx_loop(game->mlx);
	free(game->mlx);
	return (0);
}
