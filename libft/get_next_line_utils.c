/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:47:59 by marvin            #+#    #+#             */
/*   Updated: 2024/05/15 16:47:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Frees list
void	free_list(t_list *lst)
{
	if (!lst)
		return ;
	free_list(lst->next);
	free(lst->content);
	free(lst);
}

//Creates a line and allocates memory for it
void	create_line(char **line, t_list *lst)
{
	int	length;
	int	i;

	length = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
			{
				length++;
				break ;
			}
			length++;
			i++;
		}
		lst = lst->next;
	}
	*line = malloc(sizeof(char) * (length + 1));
	if (!*line)
		return ;
}

//Goes to the next element of the list
t_list	*next_element(t_list *lst)
{
	if (!lst || !lst->next)
		return (lst);
	return (ft_lstlast(lst->next));
}

//Checks if there is a new line
int	newline_check(t_list *lst)
{
	char	*content;
	int		i;

	if (!lst)
		return (0);
	content = ft_lstlast(lst)->content;
	i = 0;
	while (content[i])
	{
		if (content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
