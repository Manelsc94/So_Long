/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:11:47 by mde-agui          #+#    #+#             */
/*   Updated: 2024/09/26 23:56:21 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Sets up the game, opens window, and runs the game
void	setup_and_run_game(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	initialize_game(game);
	game->mlx = mlx_init();
	calculate_map_size(game);
	if (!game->mlx)
		exit(1);
	setup_window(game);
	load_sprites(game);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			check_on_player(game, i, j);
			j++;
		}
		i++;
	}
	map_draw(game);
	hooks_setup(game);
	mlx_loop(game->mlx);
}

//Starts the game and it's necessary components
int	start_game(int argc, char **argv, t_game *game)
{
	if (argc != 2)
		return (ft_putstr_fd("ERROR\n", 2), 1);
	game->map = read_map(argv[1]);
	if (!game->map)
		return (ft_putstr_fd("Error: reading map file\n", 2), 1);
	initialize_sprites(game);
	calculate_map_size(game);
	find_player_position(game);
	return (0);
}

//Validates the game
int	validate_game(t_game *game)
{
	if (!validate_map(game) || !validate_map_completion(game))
	{
		ft_putstr_fd("Error: Inviable map!\n", 2);
		free_map(game);
		exit(0);
	}
	if (game->player_x < 0 || game->player_y < 0 || \
	game->player_x >= game->map_width || game->player_y >= game->map_height)
		return (ft_putstr_fd("Error: Invalid player start position\n", 2), 1);
	return (0);
}

//initializes and validates the game
int	initialize_and_validate(int argc, char **argv, t_game *game)
{
	if (start_game(argc, argv, game) != 0)
		return (1);
	if (validate_game(game) != 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (initialize_and_validate(argc, argv, &game) != 0)
		return (1);
	setup_and_run_game(&game);
	return (0);
}
