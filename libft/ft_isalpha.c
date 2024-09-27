/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:15:03 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:15:03 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Checks if a char is alphabetic
int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

/*
int	main(void)
{
	char input_char = 'h';

	if (ft_isalpha(input_char))
		printf("%c is an alphabetic character.\n", input_char);
	else
		printf("%c is not an alphabetic character.\n", input_char);
	return (0);
}*/