/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asideris <asideris@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:48:30 by asideris          #+#    #+#             */
/*   Updated: 2024/04/20 15:53:36 by asideris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newcurr;
	t_list	*newlist;
	void	*content;

	if (!f || !lst || !del)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		content = f(lst->content);
		newcurr = ft_lstnew(content);
		if (!newcurr)
		{
			del(content);
			ft_lstclear(&newcurr, (*del));
			return (newlist);
		}
		ft_lstadd_back(&newlist, newcurr);
		lst = lst->next;
	}
	return (newlist);
}
