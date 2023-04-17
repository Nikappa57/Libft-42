/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:52:39 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/17 23:14:51 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static unsigned int	pow10(unsigned int exp)
{
	if (exp == 1)
		return (10);
	if (exp == 0)
		return (1);
	return (10 * pow10(exp - 1));
}

static double	ft_int(char *str)
{
	double	nbr;

	nbr = 0;
	while (ft_isdigit(*str))
		nbr = (nbr * 10) + (double)(*str++ - '0');
	return (nbr);
}

static double	ft_fractional(char *str)
{
	double	nbr;
	int		i;

	i = 0;
	nbr = 0;
	while (ft_isdigit(str[i++]))
		nbr += (double)(str[i - 1] - '0') / (double)pow10(i);
	return (nbr);
}

double	ft_atodb(char *str)
{
	char	**str_split;
	double	result;
	int		sign;

	sign = 1;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	else if (*str == '+')
		str++;
	if (ft_strchr(str, '.'))
	{
		str_split = ft_split(str, '.');
		result = ft_int(str_split[0]) + ft_fractional(str_split[1]);
	}
	else
		return (ft_int(str) * sign);
	free(str_split[0]);
	free(str_split[1]);
	free(str_split[2]);
	free(str_split);
	return (result * sign);
}
