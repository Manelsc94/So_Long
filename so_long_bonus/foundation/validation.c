/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:01:12 by mde-agui          #+#    #+#             */
/*   Updated: 2024/09/27 00:22:34 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

//Validates characters, if there is one not allowed it returns error
int	validate_character(char c, t_structure *structure)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C' && \
	c != 'X' && c != 'V')
		return (ft_printf("Error: Invalid character\n"), 0);
	if (c == 'P')
		structure->has_player++;
	if (c == 'E')
		structure->has_exit++;
	if (c == 'C')
		structure->has_collectible = 1;
	return (1);
}

//Checks on the map's components, if it has the necessary components to run it
int	check_map_components(t_game *game)
{
	t_structure	structure;

	structure.i = 0;
	structure.has_player = 0;
	structure.has_exit = 0;
	structure.has_collectible = 0;
	while (game->map[structure.i])
	{
		structure.j = 0;
		while (game->map[structure.i][structure.j])
		{
			if (!validate_character(game->map[structure.i][structure.j], \
			&structure))
				return (0);
			structure.j++;
		}
		structure.i++;
	}
	if (structure.has_player != 1 || structure.has_exit != 1 || \
	!structure.has_collectible)
		return (ft_printf("Map is invalid:(\n"), 0);
	return (1);
}

//Checks on the map structures if it is rectangular
int	check_map_structure(t_game *game)
{
	t_structure	structure;

	structure.i = 0;
	structure.width = ft_strlen(game->map[structure.i]);
	while (game->map[structure.i])
	{
		structure.j = 0;
		if (ft_strlen(game->map[structure.i]) != structure.width)
			return (0);
		if (structure.i == 0 || game->map[structure.i + 1] == NULL)
		{
			while (game->map[structure.i][structure.j])
			{
				if (game->map[structure.i][structure.j] != '1')
					return (0);
				structure.j++;
			}
		}
		else
			if (game->map[structure.i][0] != '1' || \
			game->map[structure.i][structure.width - 1] != '1')
				return (0);
		structure.i++;
	}
	return (1);
}

//Validates the map overall
int	validate_map(t_game *game)
{
	if (!check_map_structure(game))
		return (0);
	if (!check_map_components(game))
		return (0);
	ft_printf("Map validation passed\n");
	return (1);
}
