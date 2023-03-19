/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudino <lgaudino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:17:52 by lgaudino          #+#    #+#             */
/*   Updated: 2023/03/18 16:55:47 by lgaudino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;

	if (count == 18446744073709551615UL && size == 18446744073709551615UL)
		return (NULL);
	buffer = malloc(count * size);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, count * size);
	return (buffer);
}
