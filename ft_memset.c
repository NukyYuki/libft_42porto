/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:18:21 by mipinhei          #+#    #+#             */
/*   Updated: 2025/04/08 11:57:10 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*var;
	size_t			i;

	var = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		var[i] = c;
		i++;
	}
	return (s);
}
