/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 08:56:35 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/12 18:15:01 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_double(t_data *data, char *cmd_path)
{
	free_env(data->env);
	free(cmd_path);
	free_command_list(data);
	rl_clear_history();
}

int	tcheck_equal(char *input)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '=' && input[i - 1] != '\0' && input[i + 1] != '\0')
			return (0);
		i++;
	}
	return (1);
}

int	export_command1_2(t_data *data, char **token, int i, t_env *temp)
{
	int	value;

	value = 0;
	while (token[i] != NULL)
	{
		value = export_command2(token[i], temp, data);
		if (value == 1)
		{
			free_split(token);
			return (0);
		}
		if (value == 2)
		{
			free_split(token);
			return (1);
		}
		i++;
	}
	free_split(token);
	return (0);
}

int	free_redir4(int i)
{
	write(1, "\n", 1);
	i++;
	return (i);
}

int	redir_aled(int i, int *state, char **table, char *str)
{
	if (str == NULL)
	{
		i = free_redir4(i);
		*state = 1;
	}
	else if (ft_strncmp(str, table[i], 10000) == 0)
	{
		*state = 1;
		i++;
	}
	return (i);
}
