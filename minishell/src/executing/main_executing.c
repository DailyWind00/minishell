/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_executing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:24:48 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/12 16:54:49 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_last_signal_id;

int	free_things(t_data *data, char *tokens)
{
	free(tokens);
	free_env(data->env);
	free(data);
	return (0);
}

void	free_split(char **table)
{
	int	j;

	j = 0;
	while (table[j])
	{
		free(table[j]);
		j++;
	}
	free(table);
}

int	tcheck_command(t_data *data, int i, int pipe_state)
{
	char	**tokens;

	if (data->command[i].command == NULL)
		return (0);
	tokens = data->command[i].command;
	if (strncmp(tokens[0], "exit", 5) == 0)
		return (exit_command(data, tokens, i));
	if (strncmp(tokens[0], "pwd", 4) == 0)
		return (pwd_command(tokens));
	if (strncmp(tokens[0], "export", 7) == 0)
		return (export_command(data, tokens));
	if (strncmp(tokens[0], "env", 4) == 0)
		return (env_command(data));
	if (strncmp(tokens[0], "unset", 6) == 0)
		return (unset_command(data, tokens));
	if (strncmp(tokens[0], "echo", 5) == 0)
		return (echo_command(tokens));
	if (strncmp(tokens[0], "cd", 3) == 0)
		return (cd_command(data, tokens));
	if (pipe_state == -1)
		return (ls_command_pipe(data, tokens));
	else
		return (ls_command(data, tokens));
}
