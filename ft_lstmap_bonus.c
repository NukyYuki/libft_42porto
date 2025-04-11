/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:59:49 by mipinhei          #+#    #+#             */
/*   Updated: 2025/04/11 18:05:15 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel(void **ap)
{
	if (ap != 0 && *ap != 0)
	{
		free (*ap);
		*ap = NULL;
	}
}

void	clear_list(t_list *lst)
{
	t_list	*current;
	t_list	*next;

	if (!lst)
		return ;
	current = lst;
	while (current)
	{
		next = current->next;
		ft_memdel((void **)&lst);
		current = next;
	}
	lst = NULL;
}

t_list	*ft_lstmap(t_list *lst, void (*f)(void *))
{
	t_list	*current;
	t_list	*iter;

	f(lst);
	iter = ft_lstnew(lst->content);
	if (!iter)
		return (NULL);
	current = iter;
	current = current->next;
	while (current)
	{
		lst = lst->next;
		f(lst);
		current = lst;
		if (!current)
		{
			clear_list(iter);
			return (NULL);
		}
		current = current->next;
	}
	return (iter);
}
