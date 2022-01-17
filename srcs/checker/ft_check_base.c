/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamiens <ldamiens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:55:35 by ldamiens          #+#    #+#             */
/*   Updated: 2022/01/17 09:55:52 by ldamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
