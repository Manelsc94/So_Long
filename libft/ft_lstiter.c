/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:15:54 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:15:54 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Iterates over a linked list and applies a given function to each element
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
void print_content(void *content)
{
    printf("%s\n", (char *)content);
}

int main(void)
{
	t_list *node1 = malloc(sizeof(t_list));
	node1->content = ft_strdup("Node 1");
	node1->next = NULL;

	t_list *node2 = malloc(sizeof(t_list));
	node2->content = ft_strdup("Node 2");
	node2->next = NULL;

	node1->next = node2;

	t_list *list = node1;

	ft_lstiter(list, &print_content);

	return (0);
}*/