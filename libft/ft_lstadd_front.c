/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:15:38 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:15:38 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Adds an element to the front of a linked list
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*
void print_list(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%s -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}


int main(void)
{
	t_list *node2;

	node2 = ft_lstnew("Node 2");
	if (node2 == NULL)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}
	t_list *node1;

	node1 = ft_lstnew("Node 1");
	if (node1 == NULL)
	{
		printf("Memory allocation failed.\n");
		free(node2);
		return (1);
	}
	t_list *head;

	head = node2;
	ft_lstadd_front(&head, node1);

	printf("Linked list after adding node1 to the front:\n");
	print_list(head);

	free(node1);
	free(node2);
	return (0);
}*/