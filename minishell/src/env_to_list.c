/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:36:10 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/03 13:49:34 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	want_to_die(int j, t_env **env_out, char *env[], int i)
{
	char	*buffer;
	t_env	*temp;

	buffer = (char *)malloc((sizeof(char) * i + 1));
	(void)ft_strlcpy(buffer, env[j], i + 1);
	temp = ft_lstnew_name(buffer);
	if (j == 0)
		*env_out = temp;
	else
		ft_envadd_back(env_out, temp);
	free(buffer);
}

void	want_to_die2(char *env[], int i, int j, t_env **env_out)
{
	int		count2;
	t_env	*temp;
	char	*buffer;

	count2 = 0;
	while (env[j][i + count2])
		count2++;
	buffer = (char *)malloc((sizeof(char) * count2));
	count2 = 0;
	while (env[j][i + count2 + 1])
	{
		buffer[count2] = env[j][i + count2 + 1];
		count2++;
	}
	buffer[count2] = '\0';
	temp = ft_envlast(*env_out);
	temp->value = ft_strdup(buffer);
	free(buffer);
}

void	env_to_list(char *env[], t_env **env_out)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (env[j] != NULL)
	{
		while (env[j][i])
		{
			if (env[j][i] == '=')
			{
				want_to_die(j, env_out, env, i);
				want_to_die2(env, i, j, env_out);
				break ;
			}
			i++;
		}
		i = 0;
		j++;
	}
}

// Convertie la valeur NAME en sa valeur de variable d'environnement respective
// Si NAME commence par '$', cherche la variable d'environnement correspondante
char	*value_by_name(t_env **env, char *name)
{
	t_env	*temp;

	temp = *env;
	if (name[0] == '$')
	{
		name++;
		while (temp && ft_strncmp(temp->name, name, ft_strlen(name) + 1) != 0)
			temp = temp->next;
		if (!temp)
			return ("");
		else
			return (temp->value);
	}
	else
		return (name);
}

char	*value_by_name_original(t_env **env, char *name)
{
	t_env	*temp;

	temp = *env;
	while (temp && ft_strncmp(temp->name, name, ft_strlen(name) + 1) != 0)
		temp = temp->next;
	if (!temp)
		return ("");
	else
		return (temp->value);
}
