/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_chevron.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:19:43 by mgallais          #+#    #+#             */
/*   Updated: 2024/03/15 14:37:08 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	check_chevron_error(char *str, int i)
{
	while (is_chevron(str[i]) && str[i])
		i++;
	while (is_whitespace(str[i]) && str[i])
		i++;
	if (!str[i] || str[i] == '|' || is_chevron(str[i]))
		return (true);
	else
		return (false);
}

bool	check_chevron(char *str)
{
	char	save;
	int		i;

	i = 0;
	save = 0;
	while (str[i])
	{
		quote_saver(str[i], &save);
		if (is_chevron(str[i]) && !save)
		{
			if (check_chevron_error(str, i))
				return (true);
		}
		i++;
	}
	return (false);
}
