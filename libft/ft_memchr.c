/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:16:12 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:16:12 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Searches for the first ocurrence of a char in a block of memory
void	*ft_memchr(const void *str, int c, size_t n)
{
	if (n == 0)
		return (NULL);
	if (*(unsigned char *)str == (unsigned char)c)
		return ((void *)str);
	return (ft_memchr((unsigned char *)str + 1, c, n - 1));
}

/*
int main(void)
{
	const char *str;
	char c;
	size_t n;

	str = "Hello, world!"
	char c = 'o';
	n = strlen(str)
	void *result_ft = ft_memchr(str, c, n);
	void *result_standard = memchr(str, c, n);

	if (result_ft != NULL)
	{
		printf("Using ft_memchr:\n");
		printf("Character '%c' found at position: %ld\n", c,
		(char *)result_ft - str);
	}
	else
	{
		printf("Using ft_memchr:\n");
		printf("Character '%c' not found in the string.\n", c);
	}

	if (result_standard != NULL) {
		printf("\nUsing memchr for comparison:\n");
		printf("Character '%c' found at position: %ld\n", c,
		(char *)result_standard - str);
	}
	else
	{
		printf("\nUsing memchr for comparison:\n");
		printf("Character '%c' not found in the string.\n", c);
	}
	return (0);
}*/