/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loads_and_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:10:35 by mde-agui          #+#    #+#             */
/*   Updated: 2024/09/26 15:30:27 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

//Loads the component's textures
void	load_sprites(t_game *game)
{
	int	w;
	int	h;

	w = 64;
	h = 64;
	game->pl_s[0] = mlx_xpm_file_to_image(game->mlx, "texture/pl.xpm", &w, &h);
	game->pl_s[1] = mlx_xpm_file_to_image(game->mlx, "texture/pl2.xpm", &w, &h);
	game->wall_t = mlx_xpm_file_to_image(game->mlx, "texture/wall.xpm", &w, &h);
	game->coll_t = mlx_xpm_file_to_image(game->mlx, "texture/coll.xpm", &w, &h);
	game->tile_t = mlx_xpm_file_to_image(game->mlx, "texture/tile.xpm", &w, &h);
	game->exit_t = mlx_xpm_file_to_image(game->mlx, "texture/exit.xpm", &w, &h);
	game->fo_t[0] = mlx_xpm_file_to_image(game->mlx, "texture/fo.xpm", &w, &h);
	game->pa_t[0] = mlx_xpm_file_to_image(game->mlx, "texture/pa.xpm", &w, &h);
	game->fo_t[1] = mlx_xpm_file_to_image(game->mlx, "texture/fo2.xpm", &w, &h);
	game->pa_t[1] = mlx_xpm_file_to_image(game->mlx, "texture/pa2.xpm", &w, &h);
}

//Sets the components to the window
void	put_to_window(t_game *game, int i, int j)
{
	int	f;
	int	xj;
	int	xi;

	xj = j * 64;
	xi = i * 64;
	f = game->c_frame;
	mlx_put_image_to_window(game->mlx, game->win, game->tile_t, xj, xi);
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall_t, xj, xi);
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->pl_s[f], xj, xi);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->coll_t, xj, xi);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit_t, xj, xi);
	else if (game->map[i][j] == 'X')
		mlx_put_image_to_window(game->mlx, game->win, game->fo_t[f], xj, xi);
	else if (game->map[i][j] == 'V')
		mlx_put_image_to_window(game->mlx, game->win, game->pa_t[f], xj, xi);
}

//Draws the textures into the map
void	map_draw(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			put_to_window(game, i, j);
			j++;
		}
		i++;
	}
}

//Checks on the collectible
void	check_collectible(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		game->collectible--;
		game->map[y][x] = '0';
		ft_printf("Collected an item! Remaining: %d\n", game->collectible);
	}
}

//Checks the exit, if the player can use it
void	check_exit(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		if (game->collectible == 0)
		{
			ft_printf("All collectibles gathered! Exiting...\n");
			game_exit(game);
		}
		else
			ft_printf("Collect all the items before exiting!\n");
	}
}
