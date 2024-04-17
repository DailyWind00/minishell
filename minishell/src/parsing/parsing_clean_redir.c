/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_clean_redir.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:13:26 by mgallais          #+#    #+#             */
/*   Updated: 2024/04/02 15:23:45 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	clean_chevron(char *str, int *i)
{
	char	save;

	save = 0;
	while (is_chevron(str[*i]))
		(*i)++;
	while (is_whitespace(str[*i]))
		(*i)++;
	while (str[*i] && (!is_whitespace(str[*i]) || save))
	{
		quote_saver(str[*i], &save);
		(*i)++;
	}
}

// Retourne la taille pour malloc de la commande sans les redirections
static int	clean_redir_len(char *str)
{
	char	save;
	int		i;
	int		j;

	i = -1;
	j = 0;
	save = 0;
	while (++i < (int)ft_strlen(str))
	{
		quote_saver(str[i], &save);
		if (is_chevron(str[i]) && !save)
			clean_chevron(str, &i);
		j++;
	}
	return (j);
}

// Retourne la commande sans les redirections
char	*clean_redir(char *str)
{
	char	*command;
	char	save;
	int		redir_len;
	int		i;
	int		j;

	i = -1;
	j = 0;
	save = 0;
	redir_len = clean_redir_len(str);
	command = malloc(sizeof(char) * redir_len + 1);
	command[redir_len] = 0;
	while (++i < (int)ft_strlen(str))
	{
		quote_saver(str[i], &save);
		if (is_chevron(str[i]) && !save)
			clean_chevron(str, &i);
		command[j++] = str[i];
	}
	free(str);
	return (command);
}
