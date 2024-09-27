/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:16:09 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:16:09 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Calculates the size of a linked list
int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
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

	head->content = "First";
	head->next = second;
	second->content = "Second";
	second->next = third;
	third->content = "Third";
	third->next = NULL;

	int size = ft_lstsize(head);

	printf("Size of the linked list: %d\n", size);

	free(head);
	free(second);
	free(third);
	return (0);
}*/