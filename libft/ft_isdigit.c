/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:15:17 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:15:17 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Checks if a char is a digit
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

/*
int	main(void)
{
	char input_char = 'n';

	if (ft_isdigit(input_char))
		printf("%c is a digit.\n", input_char);
	else
		printf("%c is not a digit.\n", input_char);
	return (0);

}*/