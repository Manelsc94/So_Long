/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:14:58 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:14:58 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Checks if a char is alphanumeric
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*
int main(void)
{
	int	i;

	i = 48;
	if (ft_isalnum(i))
        printf("The char %c is alphanumeric\n", i);
    else
        printf("The char %c is not alphanumeric\n", i);
    return (0);
}*/