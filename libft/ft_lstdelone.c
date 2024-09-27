/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:15:50 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:15:50 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Deletes a single node from a linked list
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*
void delete_content(void *content)
{
	free(content);
}

int main(void)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
	{
		printf("Memory allocation failed!\n");
		return (1);
	}

	node->content = ft_strdup("Hello");
	node->next = NULL;

	printf("Deleting node with content: %s\n", (char *)(node->content));
	ft_lstdelone(node, delete_content);
	printf("Node deleted successfully!\n");
	printf("Node after ft_lstdelone: %s\n", (char *)(node->content));

	return (0);
}*/