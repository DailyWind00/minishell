/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:37:04 by mgallais          #+#    #+#             */
/*   Updated: 2024/02/20 16:47:59 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_the_fucking_splits(char const *s, char *c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!c_in_str(s[i], c))
		{
			count++;
			while (!c_in_str(s[i], c) && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

// ft_split but with multiple characters for spliting
char	**ft_strsplit(char const *s, char *c)
{
	size_t	i;
	size_t	j;
	size_t	start;
	char	**dest;

	i = 0;
	j = count_the_fucking_splits(s, c);
	dest = malloc(sizeof(char *) * (j + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (j < count_the_fucking_splits(s, c))
	{
		while (c_in_str(s[i], c))
			i++;
		start = i;
		while (s[i] && !c_in_str(s[i], c))
			i++;
		dest[j] = ft_strndup(s + start, i - start);
		if (!dest[j])
			return (NULL);
		j++;
	}
	dest[j] = NULL;
	return (dest);
}
