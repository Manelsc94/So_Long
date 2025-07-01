/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 01:55:13 by mde-agui          #+#    #+#             */
/*   Updated: 2024/10/04 22:11:51 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

//Counts and allocates momory to the foes
void	count_and_allocate_enemies(t_game *game)
{
	int	i;
	int	j;

	game->enemy_count = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'X' || game->map[i][j] == 'V')
				game->enemy_count++;
			j++;
		}
		i++;
	}
	if (game->enemy_count > 0)
	{
		game->enemies = (t_enemy *)malloc(sizeof(t_enemy) * game->enemy_count);
		if (!game->enemies)
			exit(1);
	}
	else
		game->enemies = NULL;
}

//Initializes the foes' position
void	initialize_enemy_positions(t_game *game)
{
	t_structure	p;

	p.enemy_i = 0;
	p.i = 0;
	while (game->map[p.i])
	{
		p.j = 0;
		while (game->map[p.i][p.j])
		{
			if (game->map[p.i][p.j] == 'X' || game->map[p.i][p.j] == 'V')
			{
				game->enemies[p.enemy_i].x = p.j;
				game->enemies[p.enemy_i].y = p.i;
				game->enemies[p.enemy_i].direction = 1;
				game->enemies[p.enemy_i].last_tile = '0';
				if (game->map[p.i][p.j] == 'X')
					game->enemies[p.enemy_i].type = 'X';
				else
					game->enemies[p.enemy_i].type = 'V';
				p.enemy_i++;
			}
			p.j++;
		}
		p.i++;
	}
}

//Initializes the foes overall
void	initialize_enemies(t_game *game)
{
	count_and_allocate_enemies(game);
	if (game->enemy_count > 0)
		initialize_enemy_positions(game);
}

//Checks if there is collision with the player, ending the game
void	check_enemy_collision(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->enemy_count)
	{
		if (game->player_x == game->enemies[i].x && \
		game->player_y == game->enemies[i].y)
		{
			ft_printf("Game Over!:(\n");
			game_exit(game);
		}
		i++;
	}
}

//Updates the game and the frames
int	update_game(t_game *game)
{
	game->frame_count++;
	if (game->frame_count >= 140)
	{
		game->c_frame = (game->c_frame + 1) % 2;
		if (game->c_frame < 0 || game->c_frame >= 2)
		{
			ft_printf("Error: Invalid frame index %d\n", game->c_frame);
			exit(1);
		}
		move_the_foe(game);
		check_enemy_collision(game);
		game->frame_count = 0;
	}
	map_draw(game);
	display_move_count(game);
	return (0);
}
