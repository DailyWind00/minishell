/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:49:01 by mgallais          #+#    #+#             */
/*   Updated: 2024/04/09 11:50:59 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Met dans la structure de la commande le type de la redirection
static int	get_redir(char *str, int i)
{
	if (str[i] == '>' && str[i + 1] == '>')
		return (DOUBLE_OUTPUT);
	if (str[i] == '>')
		return (SINGLE_OUTPUT);
	if (str[i] == '<' && str[i + 1] == '<')
		return (DOUBLE_INPUT);
	if (str[i] == '<')
		return (SINGLE_INPUT);
	return (0);
}

// Met dans la structure de la commande le nom du fichier de la redirection
static char	*get_file(char *str, int *i)
{
	char	*file;
	char	save;
	int		j;

	j = *i;
	save = 0;
	while (str[j] && is_whitespace(str[j]))
		j++;
	*i = j;
	while (str[j] && ((!is_whitespace(str[j]) && !is_chevron(str[j])) || save))
	{
		quote_saver(str[j], &save);
		j++;
	}
	file = ft_substr(str, *i, j - *i);
	*i = j - 1;
	return (remove_quotes(file));
}

// Met dans la structure de la commande les redirections
//   Retournes la commande sans les redirections
char	*parse_redirection(t_data *data, char *input, int current_command)
{
	char	save;
	int		i;
	int		current_redir;

	save = 0;
	i = -1;
	current_redir = 0;
	if (!input)
		return (free(input), NULL);
	while (++i < (int)ft_strlen(input))
	{
		quote_saver(input[i], &save);
		if (is_chevron(input[i]) && !save)
		{
			data->command[current_command].redir[current_redir].redir
				= get_redir(input, i);
			if (is_chevron(input[++i]))
				i++;
			data->command[current_command].redir[current_redir].file
				= get_file(input, &i);
			current_redir++;
		}
	}
	return (clean_redir(input));
}
