/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:05:02 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/01/25 23:06:59 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_10_pow(int n)
{
	int	result;

	result = 1;
	while (n--)
	{
		result *= 10;
	}
	return (result);
}

static int	ft_n_len(int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	while (n > 0)
	{
		ft_putchar_fd(n / ft_10_pow(ft_n_len(n) - 1), fd);
		n /= 10;
	}
}
