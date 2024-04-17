/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:05:56 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/09 09:48:36 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_envdelone(t_env *temp, t_data *data)
{
	temp->previous->next = temp->next;
	if (temp->next != NULL)
		temp->next->previous = temp->previous;
	data->env = temp;
	free(temp);
}

void	unset_2(t_data *data, t_env *temp)
{
	if (temp->previous != NULL)
		temp->previous->next = temp->next;
	if (temp->next != NULL)
		temp->next->previous = temp->previous;
	if (temp == data->env)
		data->env = temp->next;
	free(temp->name);
	free(temp->value);
	free(temp);
}

int	unset_command(t_data *data, char **token)
{
	t_env	*temp;
	char	**input;

	input = token;
	temp = data->env;
	if (input[1] == NULL)
	{
		return (0);
	}
	while (temp != NULL && strcmp(input[1], temp->name) != 0)
		temp = temp->next;
	if (!temp)
		return (0);
	if (strcmp(input[1], temp->name) == 0)
	{
		unset_2(data, temp);
		return (0);
	}
	else
	{
		return (3);
	}
}
