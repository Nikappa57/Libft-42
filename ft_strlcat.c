/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:22:29 by lgaudino          #+#    #+#             */
/*   Updated: 2023/01/26 23:41:56 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;

	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	i = 0;
	dstlen = ft_strlen(dst);
	while (dstlen + i < dstsize - 1 && src[i])
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (ft_strlen(dst) + ft_strlen((const char *)&src[i]));
}
