/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:15:57 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:15:57 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Finds the last element of a linked list
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*
int main(void)
{
	t_list *head;
	t_list *second;
	t_list *third;

	head = malloc(sizeof(t_list));
	second = malloc(sizeof(t_list));
	third = malloc(sizeof(t_list));
	if (!head || !second || !third)
	{
		printf("Memory allocation failed!\n");
		return (1);
	}

	head->content = ft_strdup("First");
	head->next = second;
	second->content = ft_strdup("Second");
	second->next = third;
	third->content = ft_strdup("Third");
	third->next = NULL;

	t_list *last = ft_lstlast(head);

	if (last != NULL)
		printf("Last element of the linked list: %s\n", (char *)last->content);
	else
		printf("The list is empty.\n");

	free(head);
	free(second);
	free(third);
	return (0);
}*/