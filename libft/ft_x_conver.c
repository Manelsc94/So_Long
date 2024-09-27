/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_conver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:33:16 by marvin            #+#    #+#             */
/*   Updated: 2024/04/30 19:33:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Passes an hexadecimal value as an argument in ft_printf 
void	ft_x_conver(unsigned int x, char type, int *count)
{
	char	hex_address[20];
	char	*hex_digits;
	int		i;

	if (type == 'x')
		hex_digits = "0123456789abcdef";
	else
		hex_digits = "0123456789ABCDEF";
	i = 0;
	if (x == 0)
		ft_c_conver('0', count);
	while (x != '\0')
	{
		hex_address[i] = hex_digits[x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		ft_c_conver(hex_address[i], count);
}
