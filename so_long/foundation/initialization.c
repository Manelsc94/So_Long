/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:02:47 by mde-agui          #+#    #+#             */
/*   Updated: 2024/09/27 00:08:40 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//Sets up the window
void	setup_window(t_game *game)
{
	int	win_width;
	int	win_height;

	win_width = game->map_width * 64;
	win_height = game->map_height * 64;
	game->win = mlx_new_window(game->mlx, win_width, win_height, "So_Long");
	if (!game->win)
	{
		ft_putstr_fd("Error: Could not create window\n", 2);
		exit(1);
	}
}

//Initializes components
void	initialize_sprites(t_game *game)
{
	game->pl_s = NULL;
	game->wall_t = NULL;
	game->coll_t = NULL;
	game->exit_t = NULL;
	game->tile_t = NULL;
}

//Initializes the game and sets some variables necessary 
void	initialize_game(t_game *game)
{
	int	i;
	int	j;

	game->player_x = 0;
	game->player_y = 0;
	game->move_count = 0;
	game->collectible = 0;
	game->last_tile = '0';
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->collectible++;
			j++;
		}
		i++;
	}
}
