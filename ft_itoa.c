/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:07:34 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/01/26 17:02:05 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_n_len(int n)
{
	int	len;

	if (!n)
		return (1);
	len = 0;
	if (n == -2147483648)
	{
		len++;
		n = -147483648;
	}
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_nbr_to_str(int n, int n_len, char *dst)
{
	dst[n_len--] = '\0';
	if (n == 0)
		dst[0] = '0';
	if (n < 0)
		dst[0] = '-';
	while (n)
	{
		if (n < 0)
		{
			dst[n_len--] = n % 10 * -1 + '0';
			n /= 10;
		}
		else
		{
			dst[n_len--] = n % 10 + '0';
			n /= 10;
		}
	}
	return (dst);
}

char	*ft_itoa(int n)
{
	int		n_len;
	char	*result;

	n_len = ft_n_len(n);
	result = malloc(n_len + 1);
	if (!result)
		return (NULL);
	return (ft_nbr_to_str(n, n_len, result));
}
