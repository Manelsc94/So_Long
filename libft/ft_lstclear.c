/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:15:47 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:15:47 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Clears and frees a linked list
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		current = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = current;
	}
}

/*
void del(void *content)
{
	free(content);
}

int main(void)
{
	t_list *list;

	list = NULL;
	t_list *node1 = malloc(sizeof(t_list));
	node1->content = ft_strdup("Node 1");
	node1->next = NULL;

	t_list *node2 = malloc(sizeof(t_list));
	node2->content = ft_strdup("Node 2");
	node2->next = NULL;

	node1->next = node2;

	list = node1;

	printf("List before clearing:\n");
	t_list *temp = list;
	while (temp != NULL)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}

	ft_lstclear(&list, &del);

	printf("\nList after clearing:\n");
	temp = list;
	while (temp != NULL)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	return (0);
}*/