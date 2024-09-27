/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:47:37 by marvin            #+#    #+#             */
/*   Updated: 2024/05/15 16:47:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Cleans up a linked list by removing nodes and retaining only 
the content after the last newline char in a new node*/
void	clean_lst(t_list **lst)
{
	t_list	*temp;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (lst == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	temp = ft_lstlast(*lst);
	i = 0;
	while (temp->content[i] && temp->content[i] != '\n')
		i++;
	if (temp->content && temp->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * \
	((ft_strlen(temp->content) - i) + 1));
	if (clean_node->content == NULL)
		return ;
	j = 0;
	while (temp->content[i])
		clean_node->content[j++] = temp->content[i++];
	clean_node->content[j] = '\0';
	free_list(*lst);
	*lst = clean_node;
}

//Extracts a line from a linked list and stores it in a string
void	extract_line(t_list *lst, char **line)
{
	int	i;
	int	j;

	if (lst == NULL)
		return ;
	create_line(line, lst);
	if (*line == NULL)
		return ;
	j = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
			{
				(*line)[j++] = lst->content[i++];
				break ;
			}
			(*line)[j++] = lst->content[i++];
		}
		lst = lst->next;
	}
	(*line)[j] = '\0';
}

//Adds a new node to the end of a linked list
void	lstnew_add(t_list **lst, char *buffer, int read_checked)
{
	int		i;
	t_list	*temp;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (read_checked + 1));
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buffer[i] && i < read_checked)
	{
		new_node->content[i] = buffer[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new_node;
}

//Reads data from  a file descriptor and stores it in a static linked list
void	read_savelst(int fd, t_list **lst, int *read_check)
{
	char	*buffer;

	while (!newline_check(*lst) && *read_check != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return ;
		*read_check = (int)read(fd, buffer, BUFFER_SIZE);
		if ((*lst == NULL && *read_check == 0) || *read_check == -1)
		{
			free(buffer);
			return ;
		}
		buffer[*read_check] = '\0';
		lstnew_add(lst, buffer, *read_check);
		free(buffer);
	}
}

//Reads a line from a file descriptor and returns it
char	*get_next_line(int fd)
{
	char			*line;
	static t_list	*lst[MAX_FD];
	int				read_checked;

	if ((fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0) \
	|| read(fd, &line, 0) < 0)
		return (NULL);
	read_checked = 1;
	line = NULL;
	read_savelst(fd, &lst[fd], &read_checked);
	if (lst[fd] == NULL)
		return (NULL);
	extract_line(lst[fd], &line);
	clean_lst(&lst[fd]);
	if (line[0] == '\0')
	{
		free_list(lst[fd]);
		lst[fd] = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
