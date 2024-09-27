/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:17:04 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:17:04 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Writes a string to a specified file descriptor followed by a new line
void	ft_putendl_fd(char *s, int fd)
{
	if (s != NULL)
	{
		while (*s != '\0')
			write(fd, s++, 1);
		write(fd, "\n", 1);
	}
}

/*
int main(void)
{
	char *s = "Hello, world!";
	int fd = 1; // STDOUT_FILENO

	ft_putendl_fd(s, fd);
	return (0);
}*/