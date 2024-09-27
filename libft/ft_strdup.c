/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:17:26 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:17:26 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Duplicates a given string
char	*ft_strdup(const char *src)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(src) + 1;
	dst = (char *)malloc(sizeof(char) * len);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, src, len);
	return (dst);
}

/*
int	main(void)
{
	const char *src;
	char *dst;

	src = "Hello, world!";
	dst = ft_strdup(src);
	if (dst == NULL)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}
	printf("Original string: %s\n", src);
	printf("Duplicated string: %s\n", dst);
	free(dst);
	return (0);
}*/