/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:15:30 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:15:30 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Adds an element to the end of a linked list
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst && new)
	{
		if (*lst)
		{
			temp = *lst;
			while (temp->next)
				temp = temp->next;
			temp->next = new;
		}
		else
		{
			*lst = new;
		}
	}
}

/*
int main(void)
{
	t_list *head;
	t_list *second;
	t_list *third;

	head = NULL;
	second = malloc(sizeof(t_list));
	third = malloc(sizeof(t_list));
	if (!second || !third)
	{
		printf("Memory allocation failed!\n");
		return (1);
	}

	second->content = "Second";
	second->next = NULL;
	third->content = "Third";
	third->next = NULL;

	ft_lstadd_back(&head, second);
	ft_lstadd_back(&head, third);

	printf("Contents of the list after adding back:\n");
	t_list *temp = head;
	while (temp != NULL)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}

	free(second);
	free(third);
	return (0);
}*/