/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:17:45 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:17:45 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Copies a string from a 'src' buffer to a 'dst' buffer, ensuring that 
the 'dst' buffer is null-terminated and does not exceed the specified size*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	copy_len;

	src_len = ft_strlen(src);
	if (size != 0)
	{
		if (src_len >= size)
			copy_len = size - 1;
		else
			copy_len = src_len;
		ft_memcpy(dst, src, copy_len);
		dst[copy_len] = '\0';
	}
	return (src_len);
}

/*
int	main(void)
{
	char	src[] = "aaa";
	char	dst[14] = "";
	unsigned int copied_size = ft_strlcpy(src, dst, 10);

    printf("Source: %s\n", src);
    printf("Destination after copying: %s\n", dst);
    printf("Number of characters copied: %u\n", copied_size);
	return (0);
}
*/