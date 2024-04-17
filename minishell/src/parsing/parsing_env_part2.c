/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_env_part2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 03:19:19 by val               #+#    #+#             */
/*   Updated: 2024/04/12 15:54:23 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_last_signal_id;

static int	handle_env_alloc(t_data *data, char *str, int *i, int *k)
{
	char	*temp;
	int		j;

	j = *i;
	while (str[j] && is_env(str[j]))
		j++;
	temp = ft_substr(str, *i, j - *i);
	*k += ft_strlen(value_by_name(&data->env, temp));
	*i = j - 1;
	free(temp);
	return (*k);
}

static int	handle_last_signal_alloc(int *i, int *k)
{
	char	*temp;

	temp = ft_itoa(g_last_signal_id);
	*k += ft_strlen(temp);
	*i += 1;
	free(temp);
	return (*k);
}

// Alloue la memoire pour la commande avec les variables d'environnement
// Transforme les variables d'environnement en leur valeur respective
int	alloc_env_command(t_data *data, char *str)
{
	int		i;
	int		k;
	char	save;

	i = -1;
	k = 0;
	save = 0;
	while (++i <= (int)ft_strlen(str))
	{
		quote_saver(str[i], &save);
		if (str[i] == '$' && save != '\'' && !is_heredoc(str, i)
			&& str[i + 1] && str[i + 1] != '?' && is_env(str[i + 1]))
			k = handle_env_alloc(data, str, &i, &k);
		else if (str[i] == '$' && str[i + 1] && !is_heredoc(str, i)
			&& str[i + 1] == '?' && save != '\'')
			k = handle_last_signal_alloc(&i, &k);
		else
			k++;
	}
	return (k);
}
