/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:14:43 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:14:43 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Sets a specified number of bytes in a memory area to zero
void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n-- > 0)
		*str++ = 0;
}

/*
int main(void)
{
	char buffer[] = "Hello, world!";

	printf("Before bzero: %s\n", buffer);
	ft_bzero(buffer, sizeof(buffer));
	printf("After bzero: %s\n", buffer);
	return (0);
}*/