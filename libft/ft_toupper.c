/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:18:25 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:18:25 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Converts lowercase to uppercase
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

/*
int	main(void)
{
	char lowercase = 'a';
	char uppercase;
	uppercase = ft_toupper(lowercase);

	printf("Original character: %c\n", lowercase);
	printf("Uppercase character: %c\n", uppercase);
	return (0);
}*/