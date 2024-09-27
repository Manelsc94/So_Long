/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_conver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:28:16 by marvin            #+#    #+#             */
/*   Updated: 2024/04/30 18:28:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Passes a string as an argument in ft_printf
void	ft_s_conver(const char *str, int *count)
{
	size_t	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		(*count) += 6;
		return ;
	}
	while (str[i] != '\0')
	{
		ft_c_conver(str[i], count);
		i++;
	}
}
