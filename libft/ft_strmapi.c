/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:17:54 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:17:54 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Applies a given function to each char of a string, 
creating a new string with the result*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	str = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}

/*
char	add_one(unsigned int index, char c)
{
	(void)index;
	return c + 1;
}

int main(void)
{
	const char *s;

	s = "Hello";
	char *result = ft_strmapi(s, &add_one);
	if (result == NULL)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}
	printf("Original string: %s\n", s);
	printf("Modified string: %s\n", result);
	free(result);
	return (0);
}*/