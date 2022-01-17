/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamiens <ldamiens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:48:28 by ldamiens          #+#    #+#             */
/*   Updated: 2022/01/17 09:31:58 by ldamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

const int	ft_resolve(char character, va_list list)
{
	if (character == 'c')
		return (ft_putchar(va_arg(list, int)));
	if (character == 's')
		return (ft_putstr(va_arg(list, char *)));
	if (character == 'p')
		return (ft_print_ptr(va_arg(list, unsigned long long)));
	if (character == 'd')
		return (ft_putnbr(va_arg(list, int)));
	if (character == 'i')
		return (ft_putnbr(va_arg(list, int)));
	if (character == 'u')
		return (ft_print_unsigned((unsigned int)va_arg(list, int *)));
	if (character == 'x')
		return (ft_print_hexa_lower(va_arg(list, unsigned int)));
	if (character == 'X')
		return (ft_print_hexa_upper(va_arg(list, unsigned int)));
	if (character == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *input, ...)
{
	int		index;
	int		count;
	va_list	list;

	index = 0;
	count = 0;
	va_start(list, input);
	while (input[index])
	{
		if (input[index] == '%' && input[index + 1])
		{
			count += ft_resolve(input[index + 1], list);
			index++;
		}
		else
			count += ft_putchar(input[index]);
		index++;
	}
	va_end(list);
	return (count);
}
