/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:30:49 by mgallais          #+#    #+#             */
/*   Updated: 2024/04/12 18:16:13 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_last_signal_id;

bool	is_heredoc(char *str, int i)
{
	i--;
	while (i >= 0 && (is_whitespace(str[i]) || is_quote(str[i])))
		i--;
	if (i >= 0 && (str[i] == '<' && str[i - 1] && str[i - 1] == '<'))
		return (true);
	return (false);
}

char	*handle_env_variable(t_data *data, char *str, t_3int *s, char *tmp)
{
	char	*temp;
	char	*buf;

	s->k = s->i;
	while (str[s->k] && is_env(str[s->k]) && str[s->k] != '\"')
		s->k++;
	temp = ft_substr(str, s->i, s->k - s->i);
	buf = value_by_name(&data->env, temp);
	ft_strlcpy(&tmp[s->j], buf, ft_strlen(buf) + 1);
	s->j += ft_strlen(buf);
	s->i = s->k - 1;
	free(temp);
	return (tmp);
}

char	*handle_last_signal_id(t_3int *s, char *tmp)
{
	char	*temp;

	temp = ft_itoa(g_last_signal_id);
	ft_strlcpy(&tmp[s->j], temp, ft_strlen(temp) + 1);
	s->j += ft_strlen(temp);
	s->i += 1;
	free(temp);
	return (tmp);
}

char	*set_env_command(t_data *data, char *b)
{
	char	*tmp;
	char	a;
	int		tmp_len;
	t_3int	s;

	s.i = -1;
	s.j = 0;
	s.k = 0;
	a = 0;
	tmp_len = alloc_env_command(data, b);
	tmp = malloc(sizeof(char) * tmp_len + 1);
	while (++s.i < (int)ft_strlen(b))
	{
		quote_saver(b[s.i], &a);
		if (b[s.i] == '$' && a != '\'' && b[s.i + 1] && b[s.i + 1] != '?'
			&& is_env(b[s.i + 1]) && !is_heredoc(b, s.i))
			tmp = handle_env_variable(data, b, &s, tmp);
		else if (b[s.i] == '$' && b[s.i + 1] && b[s.i + 1] == '?'
			&& a != '\'' && !is_heredoc(b, s.i))
			tmp = handle_last_signal_id(&s, tmp);
		else
			tmp[s.j++] = b[s.i];
	}
	tmp[tmp_len - 1] = 0;
	return (free(b), tmp);
}
