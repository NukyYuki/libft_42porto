/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:21:42 by mipinhei          #+#    #+#             */
/*   Updated: 2025/04/11 12:13:47 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_check(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*trim;
	size_t		k;

	if (!s1 && !set)
		return (NULL);
	while (set_check(*s1, set))
		s1++;
	k = ft_strlen(s1);
	while (set_check(s1[k - 1], set))
		k--;
	trim = ft_substr(s1, 0, k);
	return (trim);
}
