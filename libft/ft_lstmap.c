/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:16:00 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:16:00 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Applies a function to each element of a 
linked list and creates a new list with the results*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*content;

	new_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (new_node == NULL)
		{
			del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/*
void *add_prefix(void *content)
{
	char	*prefix;
	char	*new_content;

	prefix = "New ";
	new_content = malloc(ft_strlen(prefix) + ft_strlen((char *)content) + 1);
	ft_strlcpy(new_content, prefix, 14);
	ft_strlcat(new_content, (char *)content, 14);
	return new_content;
}

void	del(void *content)
{
	free(content);
}

int main(void)
{
	t_list *node1;
	node1 = malloc(sizeof(t_list));
	node1->content = ft_strdup("Node 1");
	node1->next = NULL;

	t_list *node2;
	node2 = malloc(sizeof(t_list));
	node2->content = ft_strdup("Node 2");
	node2->next = NULL;

	node1->next = node2;

	t_list *list = node1;

	t_list *mapped_list = ft_lstmap(list, &add_prefix, &del);

	printf("Mapped List:\n");
	t_list *temp = mapped_list;
	while (temp != NULL)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}

	ft_lstclear(&mapped_list, &del);
	return (0);
}*/