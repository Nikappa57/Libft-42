/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudino <lgaudino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:23:37 by lgaudino          #+#    #+#             */
/*   Updated: 2023/01/27 12:40:38 by lgaudino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_map;
	t_list	*temp_elem;

	if (!lst || !f)
		return (NULL);
	lst_map = NULL;
	while (lst)
	{
		temp_elem = ft_lstnew((*f)(lst->content));
		if (!temp_elem)
		{
			ft_lstclear(lst_map, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_map, temp_elem);
		lst = lst->next;
	}
	return (lst_map);
}
