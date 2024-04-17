/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_cd_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:01:27 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/12 16:51:18 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

extern int	g_last_signal_id;

int	pwd_command(char **tokens)
{
	size_t	buffer_size;
	char	*buffer;

	(void)tokens;
	buffer_size = 1024;
	buffer = (char *)malloc(buffer_size);
	if (buffer == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		rl_clear_history();
		exit(EXIT_FAILURE);
	}
	if (getcwd(buffer, buffer_size) == NULL)
	{
		fprintf(stderr, "Cannot get current working directory path\n");
		if (errno == ERANGE)
			fprintf(stderr, "Buffer size is too small.\n");
		free(buffer);
		rl_clear_history();
		exit(EXIT_FAILURE);
	}
	ft_printf("%s\n", buffer);
	free(buffer);
	return (EXIT_SUCCESS);
}

char	*pwd_for_cd(char **token)
{
	size_t	buffer_size;
	char	*buffer;

	(void)token;
	buffer_size = 1024;
	buffer = (char *)malloc(buffer_size);
	if (buffer == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		rl_clear_history();
		exit(EXIT_FAILURE);
	}
	if (getcwd(buffer, buffer_size) == NULL)
	{
		fprintf(stderr, "Cannot get current working directory path\n");
		if (errno == ERANGE)
			fprintf(stderr, "Buffer size is too small.\n");
		free(buffer);
		rl_clear_history();
		exit(EXIT_FAILURE);
	}
	return (buffer);
}

void	change_pwd(t_env **env, char *name, char **token)
{
	t_env	*temp;

	temp = *env;
	if (name[0] == '$')
	{
		name++;
		while (temp && ft_strncmp(temp->name, name, ft_strlen(name) + 1) != 0)
			temp = temp->next;
		if (!temp)
			return ;
		else
		{
			free(temp->value);
			temp->value = pwd_for_cd(token);
			return ;
		}
	}
	else
		return ;
}

int	cd_command(t_data *data, char **token)
{
	char	**input;

	input = token;
	if (input[1] == NULL)
	{
		chdir(value_by_name(&data->env, "$HOME"));
		return (0);
	}
	if (input[2] != NULL)
	{
		write(2, " too many arguments\n", 20);
		return (1);
	}
	if (chdir (input[1]) != 0)
	{
		write(2, " No such file or directory\n", 27);
		return (EXIT_FAILURE);
	}
	change_pwd(&data->env, "$PWD", token);
	return (0);
}
