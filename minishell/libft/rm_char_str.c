/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_char_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:43:32 by mgallais          #+#    #+#             */
/*   Updated: 2024/02/21 17:14:07 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
// les fonctions ne marchent pas

static int	str_length(char *str, char *set)
{
	char	save;
	int		i;
	int		j;

	i = 0;
	j = 0;
	save = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			if (save == 0)
				save = str[i];
			else
				save = 0;
		}
		if (save == 0)
			if (!ft_strchr(set, str[i]))
				j++;
		i++;
	}
	return (j);
}

// renvoie str sans les characteres dans set sauf si ils sont entre des quotes
// ne prend pas en compte les erreurs
char	*rm_char_str_quote(char *str, char *set)
{
	char	*res;
	char	save;
	int		i;

	i = 0;
	save = 0;
	res = malloc(sizeof(char) * str_length(str, set));
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			if (save == 0)
				save = str[i];
			else
				save = 0;
		}
		if (!ft_strchr(set, str[i]) && save == 0)
			res[i] = str[i];
		i++;
	}
	ft_printf("%s\n", str);
	return (res);
}

// renvoie str sans les characteres dans set
char	*rm_char_str(char *str, char *set)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (!ft_strchr(set, str[i]))
			j++;
		i++;
	}
	res = malloc(sizeof(char) * j);
	i = 0;
	while (str[i])
	{
		if (!ft_strchr(set, str[i]))
			res[i] = str[i];
		i++;
	}
	return (res);
}
