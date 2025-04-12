/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:01:37 by mipinhei          #+#    #+#             */
/*   Updated: 2025/04/12 10:51:46 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static size_t	word_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**free_tab(char **tab, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	**write_split(char const *s, char c, char **tab, size_t count)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (i < count)
	{
		while (s[j] == c)
			j++;
		len = word_len(s + j, c);
		tab[i] = ft_substr(s, j, len);
		if (!tab[i])
			return (free_tab(tab, count));
		j += len;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	count;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	tab = ft_calloc((count + 1), sizeof(char *));
	if (!tab)
		return (NULL);
	return (write_split(s, c, tab, count));
}
