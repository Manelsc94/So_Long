/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:54:57 by mde-agui          #+#    #+#             */
/*   Updated: 2024/09/27 00:02:45 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//Handles player movement and what would happen face some objects
void	player_movement(t_game *game, int move_x, int move_y)
{
	if (game->map[move_y][move_x] != '1')
	{
		game->move_count++;
		ft_printf("Move count: %d\n", game->move_count);
		check_collectible(game, move_x, move_y);
		if (game->last_tile == 'E')
			game->map[game->player_y][game->player_x] = 'E';
		else
			game->map[game->player_y][game->player_x] = '0';
		if (game->map[move_y][move_x] == 'E')
		{
			check_exit(game, move_x, move_y);
			game->last_tile = 'E';
		}
		else
			game->last_tile = '0';
		game->player_x = move_x;
		game->player_y = move_y;
		game->map[game->player_y][game->player_x] = 'P';
		map_draw(game);
	}
}

//Sets keys on keyboard to actions
int	key_handling(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		game_exit(game);
	else if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
		player_movement(game, game->player_x, game->player_y - 1);
	else if (keysym == XK_a || keysym == XK_A || keysym == XK_Left)
		player_movement(game, game->player_x - 1, game->player_y);
	else if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
		player_movement(game, game->player_x, game->player_y + 1);
	else if (keysym == XK_d || keysym == XK_D || keysym == XK_Right)
		player_movement(game, game->player_x + 1, game->player_y);
	return (0);
}

//Sets up necessary hooks
void	hooks_setup(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_handling, game);
	mlx_hook(game->win, 17, 1L << 17, game_exit, game);
}
