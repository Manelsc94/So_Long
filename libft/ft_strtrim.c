/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:18:13 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:18:13 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Removes specified chars from the beginning and end of a given string
char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*trimmed_str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trimmed_str = malloc(end - start + 1);
	if (!trimmed_str)
		return (NULL);
	ft_strlcpy(trimmed_str, &s1[start], end - start + 1);
	return (trimmed_str);
}

/*
int main(void)
{
	const char *s1 = "   Hello, world!   ";
	const char *set = " ";

	char *trimmed_str = ft_strtrim(s1, set);
	if (trimmed_str == NULL)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}
	printf("Original string: \"%s\"\n", s1);
	printf("Trimmed string: \"%s\"\n", trimmed_str);
	free(trimmed_str);
	return (0);
}*/