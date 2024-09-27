/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:16:18 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:16:18 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//It compares two blocks of memory byte by byte
int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*s1;
	const unsigned char	*s2;

	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	while (n--)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

/*
int main(void)
{
	const char *str1;
	const char *str2;
	size_t n;

	str1 = "Hello";
	str2 = "Iello";
	n = 5;
	int result_ft = ft_memcmp(str1, str2, n);

	int result_standard = memcmp(str1, str2, n);

	printf("Using ft_memcmp:\n");
	printf("Result: %d\n", result_ft);

	printf("\nUsing memcmp for comparison:\n");
	printf("Result: %d\n", result_standard);
	return (0);
}*/