/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:14:28 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:14:28 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Converts chars to ints
int	ft_atoi(const char *str)
{
	int		i;
	int		sgn;
	int		num;

	i = 0;
	sgn = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sgn *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	return (num * sgn);
}

/*
int	main(void)
{
	char str[] = "  -1234abc567";

	printf("String: \"%s\"\n", str);
	printf("Converted integer: %d\n", ft_atoi(str));
	return (0);
}*/