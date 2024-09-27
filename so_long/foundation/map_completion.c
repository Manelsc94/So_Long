/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_completion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:14:25 by mde-agui          #+#    #+#             */
/*   Updated: 2024/09/27 00:26:42 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//Copies the map, so that it can confirm if it is completable
char	**copy_map(t_game *game)
{
	int		i;
	char	**map_copy;

	i = 0;
	if (!game->map || game->map_height <= 0 || game->map_width <= 0)
		return (ft_putstr_fd("Error: Invalid map dimensions or map is NULL\n"\
		, 2), NULL);
	map_copy = malloc(sizeof(char *) * (game->map_height + 1));
	if (!map_copy)
		return (ft_putstr_fd("Error: Failed to allocate memory for map copy\n"\
		, 2), NULL);
	while (i < game->map_height)
	{
		if (!game->map[i])
			return (ft_putstr_fd("Error: Map row is NULL\n", 2), \
			free_map_copy(map_copy), NULL);
		map_copy[i] = ft_strdup(game->map[i]);
		if (!map_copy[i])
			return (ft_putstr_fd("Error: Failed to copy map row\n", 2), \
			free_map_copy(map_copy), NULL);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

//Fills the map with 'v' to see if the map can be completed
void	flood_fill(t_game *game, char **map_copy, int x, int y)
{
	if (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height || \
	map_copy[y][x] == '1' || map_copy[y][x] == 'v')
		return ;
	if (map_copy[y][x] == 'C' || map_copy[y][x] == 'E' || \
	map_copy[y][x] == '0' || map_copy[y][x] == 'P')
		map_copy[y][x] = 'v';
	flood_fill(game, map_copy, x + 1, y);
	flood_fill(game, map_copy, x - 1, y);
	flood_fill(game, map_copy, x, y + 1);
	flood_fill(game, map_copy, x, y - 1);
}

//Checks if the map can be completed
int	validate_map_completion(t_game *game)
{
	char	**map_copy;
	int		y;
	int		x;

	map_copy = copy_map(game);
	if (!map_copy)
		return (0);
	if (game->player_x < 0 || game->player_x >= game->map_width || \
	game->player_y < 0 || game->player_y >= game->map_height)
		return (free_map_copy(map_copy), ft_putstr_fd("Error: IPSP\n", 2), 0);
	flood_fill(game, map_copy, game->player_x, game->player_y);
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (map_copy[y][x] == 'C' || map_copy[y][x] == 'E')
				return (free_map_copy(map_copy), 0);
			x++;
		}
		y++;
	}
	free_map_copy(map_copy);
	return (1);
}
