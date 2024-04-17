/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:10:26 by mgallais          #+#    #+#             */
/*   Updated: 2024/03/12 15:51:36 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	check_quote_save(char *str, bool *error, char *save, int *i)
{
	while (*i != (int)ft_strlen(str))
	{
		if ((str[*i] == '\"' || str[*i] == '\''))
		{
			if (*error && str[*i] == *save)
			{
				*error = false;
				*save = 0;
			}
			else if (*save == 0)
			{
				*error = true;
				*save = str[*i];
			}
		}
		(*i)++;
	}
}

bool	check_quote(char *str)
{
	bool	error;
	char	save;
	int		i;

	error = false;
	save = 0;
	i = 0;
	if (!str)
		return (false);
	check_quote_save(str, &error, &save, &i);
	return (error);
}
