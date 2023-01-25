/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:22:29 by lgaudino          #+#    #+#             */
/*   Updated: 2023/01/25 23:37:52 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;

	i = 0;
	dstlen = ft_strlen(dst);
	while (dstlen + i < dstsize - 1 && src[i])
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	if (dstsize != 0 && dstlen <= dstsize)
		dst[dstlen + i] = '\0';
	if (dstlen > dstsize)
		dstlen = dstsize;
	return (dstlen + ft_strlen((const char *)&src[i]));
}
