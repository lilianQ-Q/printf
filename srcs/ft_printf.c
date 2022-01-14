/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamiens <ldamiens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:48:28 by ldamiens          #+#    #+#             */
/*   Updated: 2022/01/14 15:38:49 by ldamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_resolve(char character, va_list list)
{
	if (character == 'c')
		return (ft_putchar(va_arg(list, int)));
	if (character == 's')
		return (ft_putstr(va_arg(list, char *)));
	if (character == 'p')
		return (ft_putnbr_base_uint(va_arg(list, unsigned long long), "0123456789abcdef"));
	if (character == 'd')
		return (ft_putnbr_base(va_arg(list, int), "0123456789"));
	if (character == 'i')
		return (ft_putnbr(va_arg(list, int)));
	if (character == 'u')
		return (ft_putnbr_base_uint((unsigned int)va_arg(list, int *), "0123456789"));
	if (character == 'x')
		return (ft_putnbr_base(va_arg(list, int), "0123456789ABCDEF"));
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
