/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:21:48 by mgallais          #+#    #+#             */
/*   Updated: 2024/04/15 15:27:25 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	countpipe(t_data *data)
{
	char	save;
	int		i;
	int		count;

	i = 0;
	count = 0;
	save = 0;
	while (data->user_input[i])
	{
		quote_saver(data->user_input[i], &save);
		if (data->user_input[i] == '|' && !save)
			count++;
		i++;
	}
	return (count);
}

static void	loop_chvr(t_data *data, int *i, char save, int *count)
{
	if (is_chevron(data->user_input[*i]) && !save)
	{
		(*count)++;
		while (is_chevron(data->user_input[*i]))
			(*i)++;
		(*i)--;
	}
}

// Initialise la liste des commandes
void	init_command_list(t_data *data)
{
	int			i;
	int			j;
	int			count;
	char		save;

	data->command_count = countpipe(data) + 1;
	data->command = malloc(sizeof(t_command) * data->command_count);
	i = -1;
	j = 0;
	count = 0;
	save = 0;
	while (++i < (int)ft_strlen(data->user_input))
	{
		quote_saver(data->user_input[i], &save);
		loop_chvr(data, &i, save, &count);
		if ((data->user_input[i] == '|' && !save) || !data->user_input[i + 1])
		{
			data->command[j].redir_count = count;
			data->command[j++].redir = malloc(sizeof(t_redir) * count);
			count = 0;
		}
	}
}

void	free_command_list(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i != data->command_count)
	{
		j = 0;
		while (j != data->command[i].redir_count)
		{
			if (data->command[i].redir[j].file)
				free(data->command[i].redir[j].file);
			j++;
		}
		if (data->command[i].redir)
			free(data->command[i].redir);
		if (data->command[i].command)
			free_split(data->command[i].command);
		i++;
	}
	if (data->command)
		free(data->command);
	if (data->user_input)
		free(data->user_input);
}

void	free_command_list_redir(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i != data->command_count)
	{
		j = 0;
		while (j != data->command[i].redir_count)
		{
			if (data->command[i].redir[j].file)
				free(data->command[i].redir[j].file);
			j++;
		}
		i++;
	}
}
