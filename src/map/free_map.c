/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 23:01:03 by csilva-s          #+#    #+#             */
/*   Updated: 2025/11/18 23:01:03 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf/ft_printf.h"
#include "../../includes/map.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}
