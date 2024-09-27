/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:17:08 by mde-agui          #+#    #+#             */
/*   Updated: 2024/04/10 19:17:08 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Writes a number to a specified file descriptor
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + 48, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}

/*
int main(void)
{
	int n = -12345;
	int fd = 1; // STDOUT_FILENO

	t_putnbr_fd(n, fd);
	return (0);
}*/
/*
#include <fcntl.h> // Include for open() function
#include <unistd.h> // Include for close() function

int main(void)
{
    int n1 = 123;
    int n2 = -456;
    int n3 = 0;

    // Print integers to stdout (file descriptor 1)
    ft_putnbr_fd(n1, 1);
    ft_putchar_fd('\n', 1); // Print a newline for clarity
    ft_putnbr_fd(n2, 1);
    ft_putchar_fd('\n', 1);
    ft_putnbr_fd(n3, 1);
    ft_putchar_fd('\n', 1);

    // Print integers to stderr (file descriptor 2)
    ft_putnbr_fd(n1, 2);
    ft_putchar_fd('\n', 2);
    ft_putnbr_fd(n2, 2);
    ft_putchar_fd('\n', 2);
    ft_putnbr_fd(n3, 2);
    ft_putchar_fd('\n', 2);

    // Print integers to a custom file descriptor
    int custom_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (custom_fd == -1)
    {
        ft_putstr_fd("Error opening file.\n", 2);
		// Print error message to stderr (fd 2)
        return 1; // Exit with error code
    }

    ft_putnbr_fd(n1, custom_fd);
    ft_putchar_fd('\n', custom_fd);
    ft_putnbr_fd(n2, custom_fd);
    ft_putchar_fd('\n', custom_fd);
    ft_putnbr_fd(n3, custom_fd);
    ft_putchar_fd('\n', custom_fd);

    close(custom_fd); // Close the file

    return 0; // Exit success
}*/
