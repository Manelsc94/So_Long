/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:17:17 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:17:17 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_word(int count, int word)
{
	if (word)
	{
		count++;
		word = 0;
	}
	return (count);
}

static int	count_word(char *str, char c)
{
	int		i;
	int		word;
	int		count;

	i = 0;
	word = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			word = 1;
		else if (word)
		{
			count = check_word(count, word);
			word = 0;
		}
		i++;
	}
	count = check_word(count, word);
	return (count);
}

static char	*put_word(char *str, char c)
{
	int		i;
	char	*array;

	i = 0;
	array = 0;
	while (str[i] && str[i] != c)
		i++;
	array = (char *)malloc(sizeof(char) * (i + 1));
	if (!array)
		return (NULL);
	ft_strlcpy(array, str, i + 1);
	return (array);
}

void	*ft_array(int i, char **array)
{
	while (i >= 0)
		free(array[i--]);
	free(array);
	return (NULL);
}

/*Splits a string into multiple different strings 
using a specified delimiter as its seperator*/
char	**ft_split(char const *s, char c)
{
	int		i;
	int		words;
	char	**array;

	i = -1;
	if (s == NULL)
		return (NULL);
	words = count_word((char *)s, c);
	array = malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	while (++i < words)
	{
		while (s[0] == c)
			s++;
		array[i] = put_word((char *)s, c);
		if (!array[i])
		{
			ft_array(i, array);
			return (NULL);
		}
		s += ft_strlen(array[i]);
	}
	array[i] = 0;
	return (array);
}

/*
int main(void)
{
	const char *s;
	char c;
	int i;

	s = "This is a test string for the ft_split function";
	c = ' ';
	char **split_array = ft_split(s, c);

	if (split_array == NULL)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}
	printf("Original string: \"%s\"\n", s);
	printf("Split strings:\n");
	i = 0;
	while (split_array[i] != NULL)
	{
		printf("[%d]: \"%s\"\n", i, split_array[i]);
		i++;
	}
	i = 0;
	while (split_array[i] != NULL)
	{
		free(split_array[i]);
		i++;
	}
	free(split_array);
	return (0);
}*/