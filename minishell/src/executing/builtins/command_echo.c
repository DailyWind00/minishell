/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:56:06 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/04 15:31:57 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

extern int	g_last_signal_id;

void	echo_command2(int i, char **input)
{
	i++;
	while (input[i])
	{
		printf("%s", input[i]);
		i++;
		if (input[i])
			printf(" ");
	}
}

void	echo_command3(int i, char **input)
{
	while (input[i])
	{
		printf("%s", input[i]);
		i++;
		if (input[i])
			printf(" ");
	}
	printf("\n");
}

int	echo_command(char **token)
{
	int		i;

	i = 1;
	if (token[i] == NULL)
	{
		printf("\n");
		return (0);
	}
	if (strcmp(token[1], "-n") == 0)
	{
		echo_command2(i, token);
		return (0);
	}
	else
	{
		echo_command3(i, token);
		return (0);
	}
}
