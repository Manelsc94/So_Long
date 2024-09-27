/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom_and_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:08:22 by mde-agui          #+#    #+#             */
/*   Updated: 2024/09/26 23:58:40 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//Exits the game safely
int	game_exit(t_game *game)
{
	free_sprites(game);
	free_map(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
}

//Frees the allocated memory to the map
void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	free_map_copy(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

//Sets the sprites to NULL, freeing them
void	free_sprites(t_game *game)
{
	if (game->pl_s != NULL)
		mlx_destroy_image(game->mlx, game->pl_s);
	if (game->wall_t != NULL)
		mlx_destroy_image(game->mlx, game->wall_t);
	if (game->coll_t != NULL)
		mlx_destroy_image(game->mlx, game->coll_t);
	if (game->exit_t != NULL)
		mlx_destroy_image(game->mlx, game->exit_t);
	if (game->tile_t != NULL)
		mlx_destroy_image(game->mlx, game->tile_t);
}

void	free_lines(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}
