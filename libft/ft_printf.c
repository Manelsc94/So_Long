/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:29:58 by marvin            #+#    #+#             */
/*   Updated: 2024/04/30 17:29:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	spec_conver(char spec, va_list *ap, int *count)
{
	if (spec == '%')
		ft_c_conver('%', count);
	else if (spec == 'c')
		ft_c_conver(va_arg(*ap, int), count);
	else if (spec == 's')
		ft_s_conver(va_arg(*ap, char *), count);
	else if (spec == 'p')
		ft_p_conver(va_arg(*ap, size_t), count);
	else if (spec == 'd' || spec == 'i')
		ft_d_conver(va_arg(*ap, int), count);
	else if (spec == 'u')
		ft_u_conver(va_arg(*ap, unsigned int), count);
	else if (spec == 'x')
		ft_x_conver(va_arg(*ap, unsigned int), 'x', count);
	else if (spec == 'X')
		ft_x_conver(va_arg(*ap, unsigned int), 'X', count);
	return (0);
}

//Prints in STDOUT
int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			count += spec_conver(str[i], &ap, &count);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}

/*
int	main(void)
{
	char c = 'A';
	char *str = "Hello, World!";
	int num = 123;
	unsigned int unum = 456;
	unsigned int hexnum = 0xABCD;
	void *ptr = &num;

	ft_printf("Testing the printf function:\n");
	ft_printf("Character: %c\n", c);
	ft_printf("String: %s\n", str);
	ft_printf("Pointer: %p\n", ptr);
	ft_printf("Integer (decimal): %d\n", num);
	ft_printf("Integer (signed): %i\n", num);
	ft_printf("Unsigned Integer: %u\n", unum);
	ft_printf("Hexadecimal (lowercase): %x\n", hexnum);
	ft_printf("Hexadecimal (uppercase): %X\n", hexnum);
	ft_printf("Percentage sign: %%\n");

	return (0);
}

int	main()
{
	char c = 'k'; // %c
	char *str = "String test"; // %s
	char *var; var = &c;// %p
	int	nbr = -5;// %d // %i
	unsigned int nbrr = 20;// %u
	int b= 0xffffffff;// %x // %X
	// %%

	int i;
	printf("Printf replica:\n");
	i = ft_printf("| TEST TEXT |\n| Single Char: %c |\n| String: %s |\n|\
	 Pointer Adress: %p |\n| Decimal: %d |\n| Integer %i |\n| Unsign deci: %u\
	  |\n| HexLower: %x |\n| HexUpper: %X |\n| Percentage sign: %% |\n"\
	  , c, str, var, nbr, nbr, nbrr, b, b);
	printf("\nReturn Value: %d", i);
	///////////////////////////////
	printf("\nPrintf original:\n");
	i = printf("| TEST TEXT |\n| Single Char: %c |\n| String: %s |\n|\
	 Pointer Adress: %p |\n| Decimal: %d |\n| Integer %i |\n| Unsign deci: %u \
	 |\n| HexLower: %x |\n| HexUpper: %X |\n| Percentage sign: %% |\n"\
	 , c, str, var, nbr, nbr, nbrr, b, b);
	printf("\nReturn Value: %d", i);
	return (0);
}*/