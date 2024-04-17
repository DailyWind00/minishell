/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:48:03 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/12 18:14:41 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_last_signal_id;

char	*redir_4(t_data *data, int i, int j, char *temp)
{
	char	*temp2;

	if (!temp)
		temp = ft_strdup(data->command[i].redir[j].file);
	else
	{
		temp2 = ft_strjoin(temp, "\n");
		free(temp);
		temp = ft_strjoin(temp2, data->command[i].redir[j].file);
		free(temp2);
	}
	return (temp);
}

int	redir_4_2(t_data *data)
{
	int	fd;
	int	original_stdout;

	(void)data;
	original_stdout = dup(STDIN_FILENO);
	if (access("HEREDOC", R_OK) == -1)
		return (original_stdout);
	fd = open("HEREDOC", O_RDONLY);
	if (fd == -1)
	{
		perror(" ");
		return (1);
	}
	original_stdout = dup(STDIN_FILENO);
	dup2(fd, STDIN_FILENO);
	unlink("HEREDOC");
	return (original_stdout);
}

char	**redir_4_while_part2(char *oui, char **table)
{
	if (oui == NULL)
	{
		free(oui);
		free_split(table);
		return (NULL);
	}
	free_split(table);
	table = ft_split(oui, '\n');
	free(oui);
	return (table);
}

char	*redir_4_while_2(char *oui, char *str, int *state)
{
	char	*temp;

	if (!oui)
	{
		oui = str;
	}
	else
	{
		temp = ft_strjoin(oui, "\n");
		free(oui);
		oui = ft_strjoin(temp, str);
		free(str);
		free(temp);
	}
	if (*state == 1)
	{
		free(oui);
		oui = NULL;
		*state = 0;
	}
	return (oui);
}

char	**redir_4_while(char *temp, int i)
{
	char	*str;
	char	**table;
	char	*oui;
	int		state;

	table = ft_split(temp, '\n');
	oui = NULL;
	str = NULL;
	state = 0;
	set_signal();
	while (1)
	{
		str = readline("\033[34;1m>\033[0m ");
		i = redir_aled(i, &state, table, str);
		if (!table[i])
			break ;
		else
			oui = redir_4_while_2(oui, str, &state);
	}
	return (free(str), set_signal2(), redir_4_while_part2(oui, table));
}
