/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:18:20 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:18:20 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Converts uppercase to lowercase
int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

/*
int	main(void)
{
	char uppercase = 'A';
	char lowercase;
	lowercase = ft_tolower(uppercase);
	
	printf("Original character: %c\n", uppercase);
	printf("lowercase character: %c\n", lowercase);
	return (0);
}*/