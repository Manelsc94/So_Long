/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_conver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:27:24 by marvin            #+#    #+#             */
/*   Updated: 2024/04/30 19:27:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Passes an unsigned int as an argument in ft_printf 
void	ft_u_conver(unsigned int n, int *count)
{
	if (n >= 10)
		ft_d_conver(n / 10, count);
	ft_c_conver(n % 10 + 48, count);
}
