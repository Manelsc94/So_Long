/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:48:44 by mde-agui          #+#    #+#             */
/*   Updated: 2024/09/20 17:58:38 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

/*
void	move_enemy_x(t_game *game, int i, int player_x, int player_y)
{
	int enemy_x = game->enemies[i].x;
	int enemy_y = game->enemies[i].y;

	if (player_x > enemy_x && player_y > enemy_y && \
	game->map[enemy_y + 1][enemy_x + 1] != '1' && game->map[enemy_y + 1] \
	[enemy_x + 1] != 'X' && game->map[enemy_y + 1][enemy_x + 1] != 'V')
	{
		game->enemies[i].x += 1;
		game->enemies[i].y += 1;
	}
	else if (player_x > enemy_x && player_y < enemy_y && \
	game->map[enemy_y - 1][enemy_x + 1] != '1' && game->map[enemy_y - 1]\
	[enemy_x + 1] != 'X' && game->map[enemy_y - 1][enemy_x + 1] != 'V')
	{
		game->enemies[i].x += 1;
		game->enemies[i].y -= 1;
	}
	else if (player_x < enemy_x && player_y > enemy_y && \
	game->map[enemy_y + 1][enemy_x - 1] != '1' && game->map[enemy_y + 1]\
	[enemy_x - 1] != 'X' && game->map[enemy_y + 1][enemy_x - 1] != 'V')
	{
		game->enemies[i].x -= 1;
		game->enemies[i].y += 1;
	}
	else if (player_x < enemy_x && player_y < enemy_y && \
	game->map[enemy_y - 1][enemy_x - 1] != '1' && game->map[enemy_y - 1]\
	[enemy_x - 1] != 'X' && game->map[enemy_y - 1][enemy_x - 1] != 'V')
	{
		game->enemies[i].x -= 1;
		game->enemies[i].y -= 1;
	}
	else if (player_x > enemy_x && game->map[enemy_y][enemy_x + 1] != '1' && \
	game->map[enemy_y][enemy_x + 1] != 'X' && \
	game->map[enemy_y][enemy_x + 1] != 'V')
		game->enemies[i].x += 1;
	else if (player_x < enemy_x && game->map[enemy_y][enemy_x - 1] != '1' && \
	game->map[enemy_y][enemy_x - 1] != 'X' && \
	game->map[enemy_y][enemy_x - 1] != 'V')
		game->enemies[i].x -= 1;
	else if (player_y > enemy_y && game->map[enemy_y + 1][enemy_x] != '1' && \
	game->map[enemy_y + 1][enemy_x] != 'X' && \
	game->map[enemy_y + 1][enemy_x] != 'V')
		game->enemies[i].y += 1;
	else if (player_y < enemy_y && game->map[enemy_y - 1][enemy_x] != '1' && \
	game->map[enemy_y - 1][enemy_x] != 'X' && \
	game->map[enemy_y - 1][enemy_x] != 'V')
		game->enemies[i].y -= 1;
}*/

//Checks if the enemy can move into a new position
bool	can_move_diagonal(t_game *game, int new_x, int new_y)
{
	return (game->map[new_y][new_x] != '1' && game->map[new_y][new_x] != 'X' && \
	game->map[new_y][new_x] != 'V');
}

//Moves the enemy diagonally
void	move_enemy_diagonal(t_game *game, int i, int player_x, int player_y)
{
	if (player_x > game->enemies[i].x && player_y > game->enemies[i].y && \
	can_move_diagonal(game, game->enemies[i].x + 1, game->enemies[i].y + 1))
	{
		game->enemies[i].x += 1;
		game->enemies[i].y += 1;
	}
	else if (player_x > game->enemies[i].x && player_y < game->enemies[i].y && \
	can_move_diagonal(game, game->enemies[i].x + 1, game->enemies[i].y - 1))
	{
		game->enemies[i].x += 1;
		game->enemies[i].y -= 1;
	}
	else if (player_x < game->enemies[i].x && player_y > game->enemies[i].y && \
	can_move_diagonal(game, game->enemies[i].x - 1, game->enemies[i].y + 1))
	{
		game->enemies[i].x -= 1;
		game->enemies[i].y += 1;
	}
	else if (player_x < game->enemies[i].x && player_y < game->enemies[i].y && \
	can_move_diagonal(game, game->enemies[i].x - 1, game->enemies[i].y - 1))
	{
		game->enemies[i].x -= 1;
		game->enemies[i].y -= 1;
	}
}

//Moves the enemy in a straight line, vertically and horizontally
void	move_enemy_straight(t_game *game, int i, int player_x, int player_y)
{
	int	enemy_x;
	int	enemy_y;

	enemy_x = game->enemies[i].x;
	enemy_y = game->enemies[i].y;
	if (player_x > enemy_x && game->map[enemy_y][enemy_x + 1] != '1' && \
	game->map[enemy_y][enemy_x + 1] != 'X' && \
	game->map[enemy_y][enemy_x + 1] != 'V')
		game->enemies[i].x += 1;
	else if (player_x < enemy_x && game->map[enemy_y][enemy_x - 1] != '1' && \
	game->map[enemy_y][enemy_x - 1] != 'X' && \
	game->map[enemy_y][enemy_x - 1] != 'V')
		game->enemies[i].x -= 1;
	else if (player_y > enemy_y && game->map[enemy_y + 1][enemy_x] != '1' && \
	game->map[enemy_y + 1][enemy_x] != 'X' && \
	game->map[enemy_y + 1][enemy_x] != 'V')
		game->enemies[i].y += 1;
	else if (player_y < enemy_y && game->map[enemy_y - 1][enemy_x] != '1' && \
	game->map[enemy_y - 1][enemy_x] != 'X' && \
	game->map[enemy_y - 1][enemy_x] != 'V')
		game->enemies[i].y -= 1;
}

//Moves enemy
void	move_enemy_x(t_game *game, int i, int player_x, int player_y)
{
	move_enemy_diagonal(game, i, player_x, player_y);
	move_enemy_straight(game, i, player_x, player_y);
}
