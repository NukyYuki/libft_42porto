/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:01:54 by mipinhei          #+#    #+#             */
/*   Updated: 2025/04/10 19:07:35 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	next;

	while (lst != NULL)
	{
		next = lst->next;
		del(lst);
		free(lst);
		lst = NULL;
		lst = next;
	}
	*lst = NULL;
}
