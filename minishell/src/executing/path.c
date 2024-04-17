/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:34:02 by vsoltys           #+#    #+#             */
/*   Updated: 2024/04/15 15:29:36 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*find_cmd_path(char *str, t_data *data)
{
	DIR				*directory;
	struct dirent	*entry;
	char			**table;
	char			*temp;
	int				i;

	i = -1;
	table = ft_split(value_by_name_original(&data->env, "PATH"), ':');
	while (table[++i])
	{
		directory = opendir(table[i]);
		if (!directory)
			continue ;
		entry = readdir(directory);
		while (entry != NULL)
		{
			if (ft_strncmp(entry->d_name, str, ft_strlen(str) + 1) == 0)
				return (temp = ft_strdup(table[i]),
					closedir(directory), free_split(table), temp);
			entry = readdir(directory);
		}
		closedir(directory);
	}
	return (free_split(table), NULL);
}
