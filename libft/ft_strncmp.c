/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:17:58 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:17:58 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Compares up to 'n' chars of two strings
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	if (n == 0)
		return (0);
	while (*str1 == *str2 && *str1 && *str2 && n > 1)
	{
		str1++;
		str2++;
		n--;
	}
	return (((unsigned char)(*str1) - (unsigned char)(*str2)));
}

/*
int main(void)
{
	const char *str1 = "Hello";
	const char *str2 = "HellO";
	size_t n = 5;

	int result_ft = ft_strncmp(str1, str2, n);
	int result_standard = strncmp(str1, str2, n);
	printf("Using ft_strncmp:\n");
	printf("Result: %d\n", result_ft);
	printf("\nUsing strncmp for comparison:\n");
	printf("Result: %d\n", result_standard);
	return (0);
}*/