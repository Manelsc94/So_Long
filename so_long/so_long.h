/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:12:39 by mde-agui          #+#    #+#             */
/*   Updated: 2024/09/27 00:05:28 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <stdbool.h>
# include <time.h>

typedef struct s_structure
{
	int	i;
	int	j;
	int	enemy_i;
	int	width;
	int	height;
	int	has_player;
	int	has_exit;
	int	has_collectible;
}			t_structure;

typedef struct s_read
{
	int		line_count;
	int		content_found;
	char	buffer[1];
	char	**lines;
	int		i;
	char	*line;
}			t_read;

typedef struct s_game
{
	char	**map;
	char	**map_copy;
	int		map_height;
	int		map_width;
	int		player_x;
	int		player_y;
	int		collectible;
	int		move_count;
	void	*mlx;
	void	*win;
	char	last_tile;
	void	*pl_s;
	void	*wall_t;
	void	*tile_t;
	void	*coll_t;
	void	*exit_t;
	void	*fo_t;
	void	*pa_t;
}			t_game;

//Load sprites, drawing on map and checks
void	load_sprites(t_game *game);
void	map_draw(t_game *game);
void	put_to_window(t_game *game, int i, int j);
void	check_collectible(t_game *game, int x, int y);
void	check_exit(t_game *game, int x, int y);

/*Sets up hooks, sets keys for movement and moves the player,
 displaying the conter on window*/
void	hooks_setup(t_game *game);
int		key_handling(int keysym, t_game *game);
void	player_movement(t_game *game, int move_x, int move_y);

//Frees map and sprites, exits the game
void	free_sprites(t_game *game);
void	free_map(t_game *game);
void	free_map_copy(char **map);
int		game_exit(t_game *game);

//Initializes both the sprites, the game and the window
void	setup_window(t_game *game);
void	initialize_sprites(t_game *game);
void	initialize_game(t_game *game);

//Validates the map, checks for its structure and components
int		validate_map(t_game *game);
int		check_map_structure(t_game *game);
int		validate_character(char c, t_structure *structure);
int		check_map_components(t_game *game);

//Flood fills the map to check its validity
char	**copy_map(t_game *game);
void	flood_fill(t_game *game, char **map_copy, int x, int y);
int		validate_map_completion(t_game *game);

//Reads the .ber files and stores it in the map
char	**read_map(const char *file_path);
int		count_lines(const char *file_path, int *line_count, int *content_found);
char	**read_lines_from_file(const char *file_path);
char	*remove_newline(char *line);
void	calculate_map_size(t_game *game);

//Other checks, related to the player
void	find_player_position(t_game *game);
void	check_on_player(t_game *game, int i, int j);

//part of the main function
void	setup_and_run_game(t_game *game);
int		start_game(int argc, char **argv, t_game *game);
int		validate_game(t_game *game);
int		initialize_and_validate(int argc, char **argv, t_game *game);

#endif
