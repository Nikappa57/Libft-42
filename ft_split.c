/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudino <lgaudino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:19:02 by lgaudino          #+#    #+#             */
/*   Updated: 2023/01/25 13:02:33 by lgaudino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_subnbr(char const *s, char c)
{
	size_t	result;

	result = 0;
	while (*s == c && *s)
		s++;
	if (!*s)
		return (0);
	while (1)
	{
		if (!*s || *s == c)
		{
			result += 1;
			if (*s == c)
				while (*s == c)
					s++;
			if (!*s)
				break ;
		}
		else
			s++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	subnbr;
	size_t	start;
	size_t	end;
	size_t	i;

	subnbr = ft_subnbr(*s, c);
	result = malloc(subnbr + 1);
	if (!result)
		return (NULL);
	i = 0;
	end = 0;
	start = 0;
	while (i < subnbr)
	{
		if (s[end] == c || !s[end])
		{
			result[i] = ft_strtrim(ft_substr(s, start, end - start), (char *)c);
			if (result[i++] == NULL)
				return (NULL);
			start = end;
		}
		end++;
	}
	return (result);
}
