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
#include "../includes/game.h"

int	check_file_extension_ber(const char *filename)
{
	size_t	len;

	len = 0;
	while (filename[len] != '\0')
		len++;
	if (len < 4)
		return (0);
	return (filename[len - 4] == '.' && filename[len - 3] == 'b'
		&& filename[len - 2] == 'e' && filename[len - 1] == 'r');
}

static int	validate_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Usage: %s <map_file.ber>\n", argv[0]);
		return (0);
	}
	if (!check_file_extension_ber(argv[1]))
	{
		ft_printf("Error: Invalid file extension. Expected .ber\n");
		return (0);
	}
	return (1);
}

static t_map	*load_map(const char *filepath)
{
	t_map	*map;

	map = read_map(filepath);
	if (!map)
	{
		ft_printf("Error: Failed to read map.\n");
		return (NULL);
	}
	if (!validate_map(map))
	{
		free_map(map);
		return (NULL);
	}
	return (map);
}

static t_game	*initialize_game(t_map *map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		ft_printf("Error: Failed to allocate game.\n");
		free_map(map);
		return (NULL);
	}
	game_init(game, map);
	return (game);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	if (!validate_args(argc, argv))
		return (1);
	map = load_map(argv[1]);
	if (!map)
		return (1);
	game = initialize_game(map);
	if (!game)
		return (1);
	return (0);
}
