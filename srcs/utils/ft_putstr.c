/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamiens <ldamiens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:44:10 by ldamiens          #+#    #+#             */
/*   Updated: 2022/01/17 10:08:16 by ldamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *string)
{
	int	index;

	index = 0;
	if (!string)
		return (ft_putstr("(null)"));
	while (string[index])
	{
		ft_putchar(string[index]);
		index++;
	}
	return (index);
}
