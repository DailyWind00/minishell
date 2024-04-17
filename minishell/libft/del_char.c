/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:03:28 by mgallais          #+#    #+#             */
/*   Updated: 2024/03/29 12:08:56 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Retourne la taille de la chaîne str sans les caractères de set
static int	alloc_del_char(char *str, char *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (!ft_strchr(set, str[i]))
			j++;
		i++;
	}
	return (j);
}

// Supprime les caractère de set de la chaîne str
char	*del_char(char *str, char *set)
{
	char	*new;
	int		i;
	int		j;

	new = malloc(sizeof(char) * (alloc_del_char(str, set) + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (!ft_strchr(set, str[i]))
		{
			new[j] = str[i];
			j++;
		}
		i++;
	}
	new[j] = '\0';
	free(str);
	return (new);
}
