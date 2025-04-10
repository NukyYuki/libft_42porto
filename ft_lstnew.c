/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:03:41 by mipinhei          #+#    #+#             */
/*   Updated: 2025/04/10 19:09:02 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	if (content == NULL)
	{
		node->content = NULL;
	}
	else
	{
		node->content = malloc(sizeof(content));
		if (!node->content)
			return (NULL);
		ft_memmove(node->content, content, sizeof(content));
	}
	node->next = NULL;
	return (node);
}
