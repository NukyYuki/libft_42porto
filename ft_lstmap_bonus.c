/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:59:49 by mipinhei          #+#    #+#             */
/*   Updated: 2025/04/12 15:09:12 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clearmem(void *newcontent, t_list *iter, void ((*del)(void *)))
{
	del(newcontent);
	ft_lstclear(&iter, del);
	return ;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*iter;
	void	*newcontent;

	if (!lst || !f || !del)
		return (NULL);
	iter = NULL;
	while (lst)
	{
		newcontent = f(lst->content);
		if (!newcontent)
		{
			ft_lstclear(&iter, del);
			return (NULL);
		}
		temp = ft_lstnew(newcontent);
		if (!temp)
		{
			clearmem(newcontent, iter, del);
			return (NULL);
		}
		ft_lstadd_back(&iter, temp);
		lst = lst->next;
	}
	return (iter);
}
