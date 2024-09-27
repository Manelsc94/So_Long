/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:18:03 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:18:03 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Searches for the first occurence of a substring 'str2' 
within a string 'str1', up to a specified length*/
char	*ft_strnstr(char *str1, char *str2, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*str2)
		return ((char *)str1);
	i = 0;
	while (str1[i] && i < len)
	{
		j = 0;
		while (str1[i + j] == str2[j] && (i + j) < len)
		{
			if (!str2[j + 1])
				return ((char *)(str1 + i));
			j++;
		}
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char str1[] = "hello world";
	char str2[] = "l";
	size_t len = sizeof(str1);

	char *result = ft_strnstr(str1, str2, len);
	if (result != NULL)
		printf("'%s' was found in '%s' at position '%ld'\n",
			str2, str1, result - str1);
	else
		printf("'%s' was not found in '%s'\n", str2, str1);
	return (0);
}*/