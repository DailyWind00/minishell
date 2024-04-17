/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:28:38 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/11 16:06:35 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*export_command_2_part2(int i, char *input)
{
	char	*str;

	while (input[i] != '=' && input[i] != '\0')
		i++;
	str = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (input[i] != '=' && input[i] != '\0')
	{
		str[i] = input[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	export_command2(char *input, t_env *temp, t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	if (input[i] == '=')
		return (2);
	str = export_command_2_part2(i, input);
	while (temp)
	{
		if (ft_strncmp(str, temp->name, 10) == 0)
			break ;
		temp = temp->next;
	}
	i++;
	if (export_valid_string(str) == 1)
		return (free(str), 2);
	if (temp)
		return (free(str), free(temp->value), temp->value = ec3v2(i, input), 0);
	temp = ft_lstnew_name(str);
	free(str);
	if (tcheck_equal(input) == 1)
		return (ft_envadd_back(&data->env, temp), 1);
	temp = export_command3(i, input, temp);
	ft_envadd_back(&data->env, temp);
	return (0);
}

int	export_command_part2(t_data *data, char **input, t_env	*temp)
{
	int	i;
	int	value;

	i = 1;
	value = 0;
	while (input[i] != NULL)
	{
		value = export_command2(input[i], temp, data);
		if (value == 1)
		{
			return (0);
		}
		if (value == 2)
		{
			write(2, " not a valid identifier\n", 24);
			return (1);
		}
		i++;
	}
	return (0);
}

int	export_command(t_data *data, char **token)
{
	t_env	*temp;
	char	**input;

	input = token;
	temp = data->env;
	if (input[1] == NULL)
	{
		while (temp != NULL)
		{
			printf("declare -x %s=%s\n", temp->name, temp->value);
			temp = temp->next;
		}
	}
	else
		return (export_command_part2(data, input, temp));
	return (0);
}
