/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:16:47 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:16:47 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Moves 'n' bytes of momory from 'src' to 'dst'
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	if (dst_tmp == src_tmp)
		return (dst);
	else if (dst_tmp > src_tmp)
	{
		while (n--)
			dst_tmp[n] = src_tmp[n];
	}
	else
	{
		while (n--)
		{
			*dst_tmp++ = *src_tmp++;
		}
	}
	return (dst);
}

/*
int main(void)
{
	char src[] = "This is the source string.";
	char dst[50];

	printf("Before copying strng: %s\n", dst);
	ft_memmove(dst, src, ft_strlen(src) + 1);
	printf("Copied string: %s\n", dst);
	return (0);
}*/