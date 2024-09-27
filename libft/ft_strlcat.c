/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:17:42 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:17:42 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Concatenates the source string 'src' to the destination string 'dst'
 up to a specified size*/
size_t	ft_strlcat(char *dst, char *src, unsigned int size)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	j;
	size_t	i;

	i = 0;
	srclen = ft_strlen(src);
	if (dst)
		dstlen = ft_strlen(dst);
	else
		dstlen = 0;
	j = dstlen;
	if (size == 0 || size < dstlen)
		return (srclen + size);
	while (src[i] != '\0' && j < (size - 1))
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dstlen + srclen);
}

/*
int	main(void)
{
	char src[] = "Hello, ";
	char dst[20] = "world!";
	unsigned int size = 20;

	printf("Before ft_strlcat, dst: %s\n", dst);
	size_t result = ft_strlcat(src, dst, size);
	printf("After ft_strlcat, dst: %s\n", dst);
	printf("Return value of ft_strlcat: %zu\n", result);
	return (0);
}*/