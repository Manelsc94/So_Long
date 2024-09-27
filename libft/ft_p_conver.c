/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_conver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:59:18 by marvin            #+#    #+#             */
/*   Updated: 2024/04/30 18:59:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Passes a pointer as an argument for ft_printf
void	ft_p_conver(size_t ptr, int *count)
{
	char	ptr_adress[20];
	char	*hex_digits;
	int		i;

	hex_digits = "0123456789abcdef";
	i = 0;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		(*count) += 5;
	}
	else
	{
		write(1, "0x", 2);
		(*count) += 2;
		while (ptr != 0)
		{
			ptr_adress[i] = hex_digits[ptr % 16];
			ptr = ptr / 16;
			i++;
		}
		while (i--)
			ft_c_conver(ptr_adress[i], count);
	}
}
