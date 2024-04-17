/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:29:20 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/12 16:52:53 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

extern int	g_last_signal_id;

void	tcheck_exec_part2(t_data *data, char *cmd_path)
{
	if (access(cmd_path, X_OK) == -1)
	{
		if (errno == EACCES && (cmd_path[0] == '/' || cmd_path[0] == '.'))
		{
			write(2, " Permission denied\n", 18);
			free_env(data->env);
			free_command_list(data);
			rl_clear_history();
			exit(126);
		}
		else if (errno == ENOENT && (cmd_path[0] == '/' || cmd_path[0] == '.'))
		{
			write(2, " No such file or directory\n", 27);
			free_double(data, cmd_path);
			exit(127);
		}
		else
		{
			write(2, " command not found\n", 19);
			free_double(data, cmd_path);
			exit(127);
		}
	}
}

void	tcheck_exec(t_data *data, char **token)
{
	struct stat	sb;
	char		*cmd_path;
	char		*tmp;

	tmp = ft_strjoin("/", token[0]);
	cmd_path = ft_strjoin(find_cmd_path(token[0], data), tmp);
	free(tmp);
	if (!cmd_path)
		cmd_path = ft_strdup(token[0]);
	stat(cmd_path, &sb);
	tcheck_exec_part2(data, cmd_path);
	if (S_ISDIR(sb.st_mode) && (cmd_path[0] == '/' || cmd_path[0] == '.'))
	{
		write(2, " Is a directory\n", 15);
		free_double(data, cmd_path);
		exit(126);
	}
	if (S_ISDIR(sb.st_mode))
	{
		write(2, " command not found\n", 19);
		free_double(data, cmd_path);
		exit(127);
	}
	free(cmd_path);
}

int	ls_command(t_data *data, char **token)
{
	pid_t	child_pid;
	int		status;

	status = 0;
	child_pid = fork();
	if (child_pid == -1)
	{
		return (1);
	}
	if (child_pid == 0)
	{
		tcheck_exec(data, token);
		free_command_list_redir(data);
		if (token[0][0] == '/' || token[0][0] == '.')
			execve(token[0], token, data->oui);
		else
			execve(ft_strjoin(find_cmd_path(token[0], data),
					ft_strjoin("/", token[0])), token, data->oui);
		exit(errno);
	}
	else
	{
		waitpid(child_pid, &status, 0);
		return (WEXITSTATUS(status));
	}
}

int	ls_command_pipe(t_data *data, char **token)
{
	tcheck_exec(data, token);
	if (token[0][0] == '/')
		execve(token[0], token, data->oui);
	else
		execve(ft_strjoin(find_cmd_path(token[0], data),
				ft_strjoin("/", token[0])), token, data->oui);
	return (errno);
}

int	env_command(t_data *data)
{
	t_env	*temp;

	temp = data->env;
	while (temp != NULL)
	{
		printf("%s=%s\n", temp->name, temp->value);
		temp = temp->next;
	}
	return (0);
}
