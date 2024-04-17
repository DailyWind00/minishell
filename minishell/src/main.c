/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:00:25 by mgallais          #+#    #+#             */
/*   Updated: 2024/04/15 15:16:57 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern int	g_last_signal_id;

static void	init_minishell(t_data *data, char **env)
{
	if (DEBUG)
		ft_printf("/!\\ Minishell started in DEBUG MODE /!\\\n");
	data->oui = env;
	env_to_list(env, &data->env);
	data->process_state = READING_STATE;
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	(void)argc;
	(void)argv;
	init_minishell(&data, env);
	while (69)
	{
		set_signal();
		if (data.process_state == BREAK_STATE)
			break ;
		if (data.process_state == READING_STATE)
			reading(&data);
		if (data.process_state == CHECKING_STATE)
			checking(&data);
		if (data.process_state == PARSING_STATE)
			parsing(&data);
		set_signal2();
		if (data.process_state == EXECUTING_STATE)
			executing(&data);
	}
	rl_clear_history();
	free_env(data.env);
	return (g_last_signal_id);
}
