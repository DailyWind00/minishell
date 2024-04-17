/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:02:33 by mgallais          #+#    #+#             */
/*   Updated: 2024/04/12 15:08:39 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*alloc_clean_command(char *str)
{
	char	*command;
	char	save;
	int		i;
	int		j;

	i = 0;
	j = 0;
	save = 0;
	while (str[i])
	{
		quote_saver(str[i], &save);
		if (is_whitespace(str[i]) && !save)
		{
			j++;
			while (is_whitespace(str[i]))
				i++;
		}
		if (str[i] && (!is_quote(str[i]) || (save && str[i] != save)))
			j++;
		i++;
	}
	command = malloc(sizeof(char) * j + 1);
	command[j] = 0;
	return (command);
}

// Retourne la commande sans les whitespaces inutiles ni les quotes
static char	*clean_command(char *str)
{
	char	*command;
	char	save;
	int		i;
	int		j;

	command = alloc_clean_command(str);
	i = 0;
	j = 0;
	save = 0;
	while (str[i])
	{
		quote_saver(str[i], &save);
		if (is_whitespace(str[i]) && !save)
		{
			command[j++] = ' ';
			while (is_whitespace(str[i]))
				i++;
		}
		if (str[i] && (!is_quote(str[i]) || (save && str[i] != save)))
			command[j++] = str[i];
		i++;
	}
	free(str);
	return (command);
}

// Met la commande et ses arguments dans la structure de la commande
void	parse_command(t_data *data, char *command, int current_command)
{
	int		i;

	i = 0;
	while (is_whitespace(*command))
		command++;
	if (!command[0])
	{
		data->command[current_command].command = NULL;
		return ;
	}
	data->command[current_command].command = split_quote(command);
	while (data->command[current_command].command[i])
	{
		data->command[current_command].command[i]
			= clean_command(data->command[current_command].command[i]);
		i++;
	}
	data->command[current_command].argument_count = i - 1;
}
