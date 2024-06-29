/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:26:03 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/03/26 11:01:35 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nl;
	t_list	*s;

	if (!lst || !f || !del)
		return (0);
	nl = ft_lstnew(f(lst->content));
	if (!nl)
		return (0);
	s = nl;
	lst = lst->next;
	while (lst)
	{
		nl->next = ft_lstnew(f(lst->content));
		if (!nl->next)
		{
			ft_lstclear(&s, del);
			return (0);
		}
		nl = nl->next;
		lst = lst->next;
	}
	nl->next = NULL;
	return (s);
}
