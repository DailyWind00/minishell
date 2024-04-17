/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 08:21:08 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/12 17:48:18 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_last_signal_id;

int	redir_1(t_data *data, int i, int j)
{
	int	fd;
	int	original_stdout;

	fd = open(data->command[i].redir[j].file,
			O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
	{
		perror (data->command[i].redir[j].file);
		rl_clear_history();
		exit(1);
	}
	original_stdout = dup(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);
	return (original_stdout);
}

int	redir_2(t_data *data, int i, int j)
{
	int	fd;
	int	original_stdout;

	fd = open(data->command[i].redir[j].file,
			O_WRONLY | O_APPEND | O_CREAT, 0666);
	if (fd == -1)
	{
		perror (data->command[i].redir[j].file);
		rl_clear_history();
		exit(1);
	}
	original_stdout = dup(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (original_stdout);
}

int	redir_3(t_data *data, int i, int j)
{
	int	fd;
	int	original_stdout;

	fd = open(data->command[i].redir[j].file, O_RDONLY);
	if (fd == -1)
	{
		perror (data->command[i].redir[j].file);
		rl_clear_history();
		exit(1);
	}
	original_stdout = dup(STDIN_FILENO);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (original_stdout);
}

int	write_heredoc(char **table)
{
	int	i;
	int	fd;

	i = 0;
	fd = open("HEREDOC", O_CREAT | O_WRONLY, 0666);
	if (!table)
	{
		close(fd);
		return (0);
	}
	while (table[i])
	{
		write(fd, table[i], ft_strlen(table[i]));
		write(fd, "\n", 1);
		i++;
	}
	free_split(table);
	return (0);
}

void	tcheck_redir_4(t_data *data)
{
	char	*temp;
	int		i;
	int		j;

	temp = NULL;
	i = 0;
	j = 0;
	while (i <= data->command_count)
	{
		while (j != data->command[i].redir_count)
		{
			if (data->command[i].redir[j].redir == 4)
				temp = redir_4(data, i, j, temp);
			j++;
		}
		j = 0;
		i++;
	}
	if (temp)
	{
		write_heredoc(redir_4_while(temp, 0));
		free(temp);
		temp = NULL;
	}
	free(temp);
}
