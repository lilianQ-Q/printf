/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamiens <ldamiens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:45:30 by ldamiens          #+#    #+#             */
/*   Updated: 2022/01/17 10:08:12 by ldamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
