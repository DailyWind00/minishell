/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_export2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:14:26 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/12 15:44:55 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

t_env	*export_command3(int i, char *input, t_env *temp)
{
	int		k;
	char	*str;

	k = 0;
	while (input[i] && input[i] != '=')
		i++;
	i++;
	str = (char *)malloc(sizeof(char) * (ft_strlen(input) - i + 1));
	while (input[i] != '\0')
	{
		str[k] = input[i];
		i++;
		k++;
	}
	str[k] = '\0';
	temp->value = str;
	return (temp);
}

char	*ec3v2(int i, char *input)
{
	int		k;
	char	*str;

	k = 0;
	while (input[i] != '=' && input[i])
		i++;
	if (!input[i])
		return (NULL);
	i++;
	str = (char *)malloc(sizeof(char) * (ft_strlen(input) - i + 1));
	while (input[i] != '\0')
	{
		str[k] = input[i];
		i++;
		k++;
	}
	str[k] = '\0';
	return (str);
}

int	export_valid_string(char *token)
{
	int	i;

	i = 0;
	if (ft_isdigit(token[i]))
		return (1);
	while (token[i])
	{
		if (token[i] == '_' || ft_isalpha(token[i]) == 1)
			i++;
		else
			return (1);
	}
	return (0);
}
