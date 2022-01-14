/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldamiens <ldamiens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:36:32 by ldamiens          #+#    #+#             */
/*   Updated: 2022/01/14 15:23:23 by ldamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char character);
int	ft_putstr(const char *string);
int	ft_strlen(const char *string);
int	ft_putnbr(int n);
int	ft_putnbr_base(int number, const char *base);
int	ft_putnbr_base_uint(unsigned long long number, const char *base);
int	ft_printf(const char *input, ...);
#endif