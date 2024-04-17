/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:39:52 by mgallais          #+#    #+#             */
/*   Updated: 2024/04/09 11:55:05 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Permet de gerer les saves, qui permettent d'ignorer les characteres
//   a l'interieur de quotes
void	quote_saver(char c, char *save)
{
	if (is_quote(c) && !*save)
		*save = c;
	else if (c == *save)
		*save = 0;
}

static int	split_quote_alloc(char *str)
{
	int		count;
	int		i;
	char	save;

	count = 1;
	i = 0;
	save = 0;
	while (str[i])
	{
		quote_saver(str[i], &save);
		if (!save && is_whitespace(str[i]))
		{
			while (is_whitespace(str[i]))
				i++;
			if (str[i])
				count++;
		}
		else
			i++;
	}
	return (count);
}

char	**split_quote(char *str)
{
	char	**tab;
	char	save;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = 0;
	save = 0;
	tab = malloc(sizeof(char *) * (split_quote_alloc(str) + 1));
	tab[split_quote_alloc(str)] = 0;
	while (str[++i])
	{
		if ((!is_whitespace(str[i])))
		{
			j = i;
			while (str[j] && (!is_whitespace(str[j]) || save))
				quote_saver(str[j++], &save);
			tab[k++] = ft_substr(str, i, j - i);
			i = j - 1;
		}
	}
	return (tab);
}

static int	alloc_remove_quotes(char *str)
{
	int		i;
	int		j;
	char	save;

	i = 0;
	j = 0;
	save = 0;
	while (str[i])
	{
		quote_saver(str[i], &save);
		if (!is_quote(str[i]) || (save && str[i] != save))
			j++;
		i++;
	}
	return (j);
}

char	*remove_quotes(char *str)
{
	char	*new;
	int		i;
	int		j;
	char	save;

	new = malloc(sizeof(char) * (alloc_remove_quotes(str) + 1));
	i = 0;
	j = 0;
	save = 0;
	while (str[i])
	{
		quote_saver(str[i], &save);
		if (!is_quote(str[i]) || (save && str[i] != save))
			new[j++] = str[i];
		i++;
	}
	new[j] = 0;
	free(str);
	return (new);
}
