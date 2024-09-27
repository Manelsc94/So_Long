/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:14:49 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:14:49 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Allocates mamory for an array of elements
void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(size * num);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, size * num);
	return ((void *)ptr);
}

/*
int main(void)
{
	size_t num_elements = 5;
	size_t element_size = sizeof(int);

	int *arr = (int *)ft_calloc(num_elements, element_size);
	if (arr == NULL)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}
	memset(arr, 0, num_elements * element_size);
	int *ptr = arr;
	int *end = arr + num_elements;
	int value = 1;
	while (ptr < end)
		*ptr++ = value++;
	printf("Allocated array:\n");
	ptr = arr;
	while (ptr < end)
		printf("%d ", *ptr++);
	printf("\n");
	free(arr);
	return (0);
}*/