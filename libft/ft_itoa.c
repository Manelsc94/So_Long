/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:15:25 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:15:25 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_size(int num)
{
	size_t	size;

	size = 0;
	if (num <= 0)
		size++;
	while (num != 0)
	{
		num /= 10;
		size++;
	}
	return (size);
}

//Converts an int into a char
char	*ft_itoa(int n)
{
	char	*ptr;
	size_t	i;
	int		signal;

	i = number_size(n);
	signal = 1;
	ptr = malloc((i + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr[i] = '\0';
	if (n == 0)
		ptr[0] = 48;
	else if (n < 0)
	{
		signal = -1;
		ptr[0] = '-';
	}
	while (n != 0)
	{
		i--;
		ptr[i] = (n % 10 * signal) + 48;
		n /= 10;
	}
	return (ptr);
}

/*
int main(void)
{
	int num = -12345;
	char *str = ft_itoa(num);

	if (str == NULL)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}
	printf("Original number: %d\n", num);
	printf("Converted string: %s\n", str);
	free(str);
	return (0);
}*/