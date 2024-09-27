/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:54:57 by mde-agui          #+#    #+#             */
/*   Updated: 2024/09/20 19:13:24 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

//Handles player movement and what would happen face some objects
void	player_movement(t_game *game, int move_x, int move_y)
{
	if (game->map[move_y][move_x] == 'X')
		game_exit(game);
	if (game->map[move_y][move_x] == 'V')
		game_exit(game);
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

//Displays the move counter on the window, rather than on the shell 
void	display_move_count(t_game *game)
{
	char	*move_count_str;

	move_count_str = ft_itoa(game->move_count);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, "Moves: ");
	mlx_string_put(game->mlx, game->win, 80, 10, 0xFFFFFF, move_count_str);
	free(move_count_str);
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
	mlx_loop_hook(game->mlx, update_game, game);
	mlx_hook(game->win, 17, 1L << 17, game_exit, game);
}
