/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:09:34 by mgallais          #+#    #+#             */
/*   Updated: 2024/04/03 19:35:05 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	check_pipe_error(char *str, int i)
{
	int	input_length;
	int	j;

	j = i;
	input_length = (int)ft_strlen(str);
	while (--j >= -1000)
	{
		if (j < 0 || str[j] == '|')
			return (true);
		else if (!is_whitespace(str[j]))
			break ;
	}
	j = i;
	while (++j <= input_length + 1)
	{
		if (str[j] == '|' || j >= input_length)
			return (true);
		else if (!is_whitespace(str[j]))
			break ;
	}
	return (false);
}

bool	check_pipe(char *str)
{
	char	save;
	int		i;

	i = 0;
	save = 0;
	while (str[i])
	{
		quote_saver(str[i], &save);
		if (str[i] == '|' && !save)
		{
			if (check_pipe_error(str, i))
				return (true);
		}
		i++;
	}
	return (false);
}
