/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:58:18 by mde-agui          #+#    #+#             */
/*   Updated: 2024/09/27 00:11:38 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//Calculates map size
void	calculate_map_size(t_game *game)
{
	game->map_height = 0;
	game->map_width = 0;
	while (game->map[game->map_height])
		game->map_height++;
	game->map_width = ft_strlen(game->map[0]);
}

//Removes newlines read from the gnl
char	*remove_newline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

//Counts lines and check for content
int	count_lines(const char *file_path, int *line_count, int *content_found)
{
	int		fd;
	char	buffer[1];

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error opening map file\n", 2), -1);
	*line_count = 0;
	*content_found = 0;
	while (read(fd, buffer, 1) > 0)
	{
		if (buffer[0] != '\n')
			*content_found = 1;
		if (buffer[0] == '\n')
			(*line_count)++;
	}
	if (*content_found == 0)
		return (ft_putstr_fd("Error: Map is empty or has only newlines\n", 2), \
		close(fd), -1);
	if (buffer[0] != '\n')
		(*line_count)++;
	close(fd);
	return (0);
}

//Reads lines from fd
char	**read_lines_from_file(const char *file_path)
{
	t_read	file;
	int		fd;

	if (count_lines(file_path, &file.line_count, &file.content_found) < 0)
		return (NULL);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error reopening map file\n", 2), NULL);
	file.lines = (char **)malloc(sizeof(char *) * (file.line_count + 1));
	if (!file.lines)
		return (ft_putstr_fd("Error allocating memory\n", 2), close(fd), NULL);
	file.i = 0;
	file.line = get_next_line(fd);
	while (file.line)
	{
		file.lines[file.i] = ft_strdup(remove_newline(file.line));
		if (!file.lines[file.i])
			return (ft_putstr_fd("Error duplicating\n", 2), close(fd), NULL);
		free(file.line);
		file.i++;
		file.line = get_next_line(fd);
	}
	file.lines[file.i] = NULL;
	close(fd);
	return (file.lines);
}

// Processes the lines and creates the map
char	**read_map(const char *file_path)
{
	t_read	file;
	char	**map;

	file.lines = read_lines_from_file(file_path);
	if (!file.lines)
		return (NULL);
	file.line_count = 0;
	while (file.lines[file.line_count])
		file.line_count++;
	if (file.line_count == 0)
		return (ft_putstr_fd("Error: No valid lines in the map\n", 2), \
		free(file.lines), NULL);
	map = (char **)malloc(sizeof(char *) * (file.line_count + 1));
	if (!map)
		return (ft_putstr_fd("Error allocating memory for map\n", 2), NULL);
	file.i = 0;
	while (file.lines[file.i])
	{
		map[file.i] = file.lines[file.i];
		file.i++;
	}
	map[file.i] = NULL;
	free(file.lines);
	return (map);
}
