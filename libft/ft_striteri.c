/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:17:32 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:17:32 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Applies a given function to each char of a string,
 passing the char's index and a pointer to the char to the function*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}

/*
void	capitalize(unsigned int i, char *str)
{
	*str = ft_toupper(*str);
	(void)i;
}

int main(void)
{
	char s[] = "hello, world!";

	ft_striteri(s, &capitalize);
	printf("Modified string: %s\n", s);
	return (0);
}*/