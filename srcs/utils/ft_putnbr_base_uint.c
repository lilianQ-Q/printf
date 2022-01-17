/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_uint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamiens <ldamiens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:14:52 by ldamiens          #+#    #+#             */
/*   Updated: 2022/01/17 09:15:13 by ldamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
		if (number == 0)
			return (ft_putchar(base[0]));
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