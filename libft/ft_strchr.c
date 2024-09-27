/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:17:20 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:17:20 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Searches for the first occurrence of a char in a string
char	*ft_strchr(const char *str, int c)
{
	int	i;

	c %= 256;
	i = 0;
	while (str[i] != c)
	{
		if (str[i] == '\0')
		{
			if (c == '\0')
				return ((char *)str);
			return (0);
		}
		str++;
	}
	return ((char *)str);
}

/*
int	main(void)
{
	const char *str;
	char c;
	char *result;

	const char *str = "Hello, world!";
	c = '\0';
	result = ft_strchr(str, c);
	if (result != NULL)
		printf("Character '%c' found at position: %ld\n", c, result - str);
	else
		printf("Character '%c' not found in the string.\n", c);
	return (0);
}*/