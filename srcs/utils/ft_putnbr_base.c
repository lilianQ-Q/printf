/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamiens <ldamiens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:45:30 by ldamiens          #+#    #+#             */
/*   Updated: 2022/01/17 09:38:51 by ldamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_check_base(const char *base)
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
	int	final[100];
	int	index;
	int	count;

	index = 0;
	count = 0;
	if (!ft_check_base(base))
		return (0);
	if (number < 0)
	{
		number = -number;
		count += ft_putchar('-');
	}
	if (number == 0)
		count += ft_putchar(base[0]);
	while (number)
	{
		final[index] = number % ft_strlen(base);
		number = number / ft_strlen(base);
		index++;
	}
	while (--index >= 0)
		count += ft_putchar(base[final[index]]);
	return (count);
}
