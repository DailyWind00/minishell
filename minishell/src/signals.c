/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:19:36 by mgallais          #+#    #+#             */
/*   Updated: 2024/04/11 15:55:10 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	g_last_signal_id = 0;

static void	check_signal(int sig)
{
	if (sig == SIGINT)
	{
		ft_printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_last_signal_id = 130;
	}
	else
		g_last_signal_id = -1;
}

static void	check_signal2(int sig)
{
	if (sig == SIGINT)
	{
		ft_printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		g_last_signal_id = 130;
	}
	else
		g_last_signal_id = -1;
}

void	set_signal(void)
{
	signal(SIGINT, check_signal);
	signal(SIGQUIT, SIG_IGN);
}

void	set_signal2(void)
{
	signal(SIGINT, check_signal2);
	signal(SIGQUIT, SIG_IGN);
}
