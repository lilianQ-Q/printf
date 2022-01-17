/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamiens <ldamiens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:12:21 by ldamiens          #+#    #+#             */
/*   Updated: 2022/01/17 10:13:04 by ldamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa_lower(unsigned int number)
{
	return (ft_putnbr_base_uint(number, "0123456789abcdef"));
}

int	ft_print_hexa_upper(unsigned int number)
{
	return (ft_putnbr_base_uint(number, "0123456789ABCDEF"));
}

int	ft_print_ptr(unsigned long long number)
{
	ft_putstr("0x");
	return (ft_putnbr_base_uint(number, "0123456789abcdef") + 2);
}
