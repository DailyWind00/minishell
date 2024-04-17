/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:15:21 by mgallais          #+#    #+#             */
/*   Updated: 2024/04/15 15:14:50 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_last_signal_id;

static void	child_redir(t_data *data, int i, int j)
{
	if (data->command[i].redir[j].redir == 1)
		redir_1(data, i, j);
	else if (data->command[i].redir[j].redir == 2)
		redir_2(data, i, j);
	else if (data->command[i].redir[j].redir == 3)
		redir_3(data, i, j);
	else if (data->command[i].redir[j].redir == 4)
		redir_4_2(data);
}

void	child(t_data *data, int i, int j, int fd[3])
{
	j = -1;
	if (i != 0)
	{
		dup2(fd[2], STDIN_FILENO);
		close(fd[2]);
	}
	if (i != data->command_count)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
	}
	while (++j != data->command[i].redir_count)
	{
		child_redir(data, i, j);
		if (data->command[i].redir[j].redir == 4)
			break ;
	}
	g_last_signal_id = tcheck_command(data, i, -1);
	free_env(data->env);
	data->command_count++;
	free_command_list(data);
	rl_clear_history();
	exit(g_last_signal_id);
}

void	bourrage_pipe_and_redir(int i, pid_t pid)
{
	int	status;

	while (i != 0)
	{
		waitpid(pid, &status, WUNTRACED);
		if (WEXITSTATUS(status) != 0)
			g_last_signal_id = WEXITSTATUS(status);
		i--;
	}
}

void	pipe_and_redir(t_data *data, int i, int j, int input_fd)
{
	int		fd[2];
	pid_t	pid;

	data->command_count--;
	tcheck_redir_4(data);
	while (i <= data->command_count)
	{
		if (i != data->command_count)
			pipe(fd);
		pid = fork();
		if (pid < 0)
			exit(EXIT_FAILURE);
		if (pid == 0)
			child(data, i, j, (int [3]){fd[0], fd[1], input_fd});
		else
		{
			if (i != 0)
				close(input_fd);
			if (i != data->command_count)
				close(fd[1]);
			input_fd = fd[0];
		}
		i++;
	}
	bourrage_pipe_and_redir(i, pid);
}

void	executing(t_data *data)
{
	if (!data->user_input[0])
	{
		free(data->user_input);
		free(data->command);
		data->process_state = READING_STATE;
		g_last_signal_id = 0;
		return ;
	}
	if (data->command[0].redir_count >= 1 || data->command_count >= 2)
	{
		pipe_and_redir(data, 0, 0, STDIN_FILENO);
		data->command_count++;
	}
	else
		g_last_signal_id = tcheck_command(data, 0, 1);
	free_command_list(data);
	data->process_state = READING_STATE;
}
