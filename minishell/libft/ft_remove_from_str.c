/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_from_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:07:25 by vsoltys           #+#    #+#             */
/*   Updated: 2024/03/14 08:51:07 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_rmv_char(char *str, char c)
{
	int		i;
	int		j;
	char	*returnstr;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
			j++;
		i++;
	}
	returnstr = (char *)malloc(sizeof(char) * (i - j + 1));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c)
			returnstr[i - j] = str[i];
		else
			j++;
		i++;
	}
	returnstr[i] = '\0';
	return (returnstr);
}
