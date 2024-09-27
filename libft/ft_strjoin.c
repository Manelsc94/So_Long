/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:17:37 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:17:37 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Concatenates two strings into a newly allocated string
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2);
	str[len1 + len2] = '\0';
	return (str);
}

/*
int main(void)
{
	const char *s1;
	const char *s2;
	char *result;

	s1 = "Hello, ";
	s2 = "world!";
	result = ft_strjoin(s1, s2);
	if (result == NULL)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}
	printf("Result: %s\n", result);
	free(result);
	return (0);
}*/