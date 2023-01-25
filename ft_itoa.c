/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:07:34 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/01/25 23:11:32 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static int	ft_sign(int n)
{
	if (n < 0)
		return (-1);
	return (0);
}

char	*ft_itoa(int n)
{
	int		n_len;
	char	*result;
	int		sign;

	sign = ft_sign(n);
	if (sign == -1)
		n *= -1;
	n_len = 0;
	n_len = ft_n_len(n);
	result = malloc(n_len + sign + 1);
	if (!result)
		return (NULL);
	while (n > 0)
	{
		result[--n_len] = n % 10 + '0';
		n /= 10;
	}
	if (sign)
		result[--n_len] = '-';
	result[n_len] = '\0';
	return (result);
}
