/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:16:21 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:16:21 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Copies 'n' bytes from the memory area 'src' to the memory area 'dst'
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	i = 0;
	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	if (!n || dst == src)
		return (dst);
	while (i < n)
	{
		dst_tmp[i] = src_tmp[i];
		i++;
	}
	return (dst);
}

/*
int main(void)
{
	char src[] = "This is the source string.";
	char dst[50];

	printf("Before copying string: %s\n", dst);
	ft_memcpy(dst, src, sizeof(src));
	printf("After copying string: %s\n", dst);
	return (0);
}*/