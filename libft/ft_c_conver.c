/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_conver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:23:45 by mde-agui          #+#    #+#             */
/*   Updated: 2024/09/04 12:45:41 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Passes a char argument for ft_printf
void	ft_c_conver(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}
