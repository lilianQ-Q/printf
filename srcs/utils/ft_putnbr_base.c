/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamiens <ldamiens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:45:30 by ldamiens          #+#    #+#             */
/*   Updated: 2022/01/14 15:42:10 by ldamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_base(const char *base)
{
	int	index;
	int	second;

	index = 0;
	second = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[index])
	{
		second = index + 1;
		if (base[index] == '+' || base[index] == '-')
			return (0);
		if (base[index] < 32 || base[index] > 126)
			return (0);
		while (base[second])
		{
			if (base[index] == base[second])
				return (0);
			second++;
		}
		index++;
	}
	return (1);
}

int	ft_putnbr_base(int number, const char *base)
{
	int	size_base;
	int	final[100];
	int	index;
	int	count;

	index = 0;
	count = 0;
	size_base = ft_strlen(base);
	if (!ft_check_base(base))
		return (0);
	if (number < 0)
	{
		number = -number;
		count += ft_putchar('-');
	}
	while (number)
	{
		final[index] = number % size_base;
		number = number / size_base;
		index++;
	}
	while (--index >= 0)
		count += ft_putchar(base[final[index]]);
	return (count);
}

int	ft_putnbr_base_uint(unsigned long long number, const char *base)
{
	int	size_base;
	int	final[100];
	int	index;
	int	count;

	index = 0;
	size_base = 0;
	count = 0;
	if (ft_check_base(base))
	{
		while (base[size_base])
			size_base++;
		while (number)
		{
			final[index] = number % size_base;
			number = number / size_base;
			index++;
		}
		while (--index >= 0)
			count += ft_putchar(base[final[index]]);
	}
	return (count);
}
