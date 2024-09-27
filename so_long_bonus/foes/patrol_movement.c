/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:50:46 by mde-agui          #+#    #+#             */
/*   Updated: 2024/09/20 18:07:16 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

//Moves the patrol, randomly, vertically and horizontally
void	move_enemy_v(t_game *game, int i)
{
	int	enemy_x;
	int	enemy_y;
	int	direction;

	enemy_x = game->enemies[i].x;
	enemy_y = game->enemies[i].y;
	direction = rand() % 4;
	if (direction == 0 && game->map[enemy_y][enemy_x + 1] != '1' && \
	game->map[enemy_y][enemy_x + 1] != 'X' && \
	game->map[enemy_y][enemy_x + 1] != 'V')
		game->enemies[i].x += 1;
	else if (direction == 1 && game->map[enemy_y][enemy_x - 1] != '1' && \
	game->map[enemy_y][enemy_x - 1] != 'X' && \
	game->map[enemy_y][enemy_x - 1] != 'V')
		game->enemies[i].x -= 1;
	else if (direction == 2 && game->map[enemy_y + 1][enemy_x] != '1' && \
	game->map[enemy_y + 1][enemy_x] != 'X' && \
	game->map[enemy_y + 1][enemy_x] != 'V')
		game->enemies[i].y += 1;
	else if (direction == 3 && game->map[enemy_y - 1][enemy_x] != '1' && \
	game->map[enemy_y - 1][enemy_x] != 'X' && \
	game->map[enemy_y - 1][enemy_x] != 'V')
		game->enemies[i].y -= 1;
}

//Updates the map, so that the collectibles aren't eaten by the foes
void	update_map(t_game *game, int i, int prev_x, int prev_y)
{
	if (game->enemies[i].last_tile == 'C')
		game->map[prev_y][prev_x] = 'C';
	else if (game->enemies[i].last_tile == 'E')
		game->map[prev_y][prev_x] = 'E';
	else
		game->map[prev_y][prev_x] = '0';
	if (game->map[game->enemies[i].y][game->enemies[i].x] == 'C')
		game->enemies[i].last_tile = 'C';
	else if (game->map[game->enemies[i].y][game->enemies[i].x] == 'E')
		game->enemies[i].last_tile = 'E';
	else
		game->enemies[i].last_tile = '0';
	game->map[game->enemies[i].y][game->enemies[i].x] = game->enemies[i].type;
}

//Moves the enemy
void	move_the_foe(t_game *game)
{
	int	i;
	int	player_x;
	int	player_y;
	int	prev_x;
	int	prev_y;

	i = 0;
	player_x = game->player_x;
	player_y = game->player_y;
	while (i < game->enemy_count)
	{
		prev_x = game->enemies[i].x;
		prev_y = game->enemies[i].y;
		if (game->enemies[i].type == 'X')
			move_enemy_x(game, i, player_x, player_y);
		else if (game->enemies[i].type == 'V')
			move_enemy_v(game, i);
		update_map(game, i, prev_x, prev_y);
		i++;
	}
	map_draw(game);
}
