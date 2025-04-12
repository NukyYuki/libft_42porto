/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:24:56 by mipinhei          #+#    #+#             */
/*   Updated: 2025/04/12 18:53:55 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*iter;

	if (!s)
		return (0);
	i = 0;
	iter = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!iter)
		return (NULL);
	while (s[i])
	{
		iter[i] = f(i, s[i]);
		i++;
	}
	iter[i] = '\0';
	return (iter);
}
