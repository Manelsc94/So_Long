/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:16:06 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:16:06 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Creates a new node for a linked list
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*
int main(void)
{
	t_list *node;

	node = ft_lstnew("Hello, world!");
	if (node == NULL)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}
	printf("Content of the node: %s\n", (char *)node->content);
	free(node);
	return (0);
}*/