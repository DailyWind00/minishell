/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:25:49 by vsoltys           #+#    #+#             */
/*   Updated: 2024/03/25 08:45:15 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	countoccur(char const *s, int i, char c)
{
	int	num;

	num = 0;
	while (s[i] && s[i] != c)
	{
		num++;
		i++;
	}
	return (num);
}

static int	compteurmots(char const *s, char c)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i + 1])
	{
		if (s[i] == c && s[i + 1] != c)
			num++;
		i++;
	}
	if (s[0] != c)
		num++;
	return (num);
}

static char	**souspartie(const char *s, char **str, char c, int i)
{
	int		j;
	int		k;

	j = 0;
	while (s[i])
	{
		if (s[i] && s[i] == c)
			i++;
		else
		{
			str[j] = (char *)malloc(sizeof(char) * (countoccur(s, i, c) + 1));
			k = 0;
			while (s[i] && s[i] != c)
			{
				str[j][k] = s[i];
				i++;
				k++;
			}
			str[j][k] = '\0';
			str[j] = ft_strtrim(str[j], "\"");
			j++;
		}
	}
	return (str);
}

char	**c_split(char const *s, char c)
{
	char	**str;
	int		n;

	if (!s)
		return (NULL);
	n = compteurmots(s, c);
	str = (char **)malloc(sizeof(char *) * (n + 1));
	if (str == NULL)
		return (NULL);
	str[n] = NULL;
	return (souspartie(s, str, c, 0));
}
