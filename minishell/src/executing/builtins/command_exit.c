/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:48:27 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/15 15:27:02 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

extern int	g_last_signal_id;

void	exit_command_part2(t_data *data, char **split, int i)
{
	while (split[1][i])
	{
		if (ft_isdigit(split[1][i]) == 0 && !(split[1][i] == '-') &&
			!(split[1][i] == '+') && !(split[1][i] == '"'))
		{
			write(2, " numeric argument required\n", 27);
			free_env(data->env);
			free_command_list(data);
			rl_clear_history();
			exit(2);
		}
		i++;
	}
}

int	exit_command(t_data *data, char **token, int cmd_count)
{
	int		return_code;
	int		i;
	char	**split;
	char	*tmp;

	i = 0;
	split = token;
	if (data->command[cmd_count].argument_count >= 2)
		return (write(2, " too many arguments\n", 20), 1);
	if (!split[1])
	{
		free_env(data->env);
		free_command_list(data);
		rl_clear_history();
		exit (0);
	}
	exit_command_part2(data, split, i);
	tmp = ft_str_rmv_char(split[1], '\"');
	return_code = ft_atoi(split[1]);
	return_code = return_code % 256;
	free(tmp);
	free_env(data->env);
	free_command_list(data);
	rl_clear_history();
	exit(return_code);
}
