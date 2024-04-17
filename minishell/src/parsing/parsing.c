/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:39:44 by mgallais          #+#    #+#             */
/*   Updated: 2024/04/12 15:24:24 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// debug
static void	print_command(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_printf("\nParsing\n");
	while (i != data->command_count)
	{
		ft_printf("Command : %i\n", i + 1);
		if (data->command[i].command)
			ft_printf("\tCmd : %s\n", data->command[i].command[0]);
		ft_printf(" Arg count : %i\n", data->command[i].argument_count);
		while (++j != data->command[i].argument_count + 1)
			ft_printf("\t Arg [%i] : %s\n", j, data->command[i].command[j]);
		j = -1;
		ft_printf(" Redir count : %i\n", data->command[i].redir_count);
		while (++j != data->command[i].redir_count)
		{
			ft_printf("\tRedir [%i] :\n", j + 1);
			ft_printf("\t Type : %i\n", data->command[i].redir[j].redir);
			ft_printf("\t File : %s\n", data->command[i].redir[j].file);
		}
		j = 0;
		i++;
	}
}

// retire les whitespaces au debut et a la fin et le pipe de fin
static char	*ft_cleanstr(char *str)
{
	char	save;
	int		i;
	int		j;

	i = 0;
	j = 0;
	save = 0;
	while (is_whitespace(str[i]))
		i++;
	while (str[j] && (str[j] != '|' || save))
	{
		quote_saver(str[j], &save);
		j++;
	}
	while (j > 0 && is_whitespace(str[j - 1]))
		j--;
	return (ft_substr(str, i, j - i));
}

// coupe l'input de l'user en fonction des pipes
static char	**cut_inputs(t_data *data)
{
	char	**inputs;
	char	save;
	char	*str;
	t_3int	i;

	i.i = 0;
	i.j = -1;
	i.k = 0;
	save = 0;
	inputs = malloc(sizeof(char *) * data->command_count);
	while (data->user_input[++i.j])
	{
		quote_saver(data->user_input[i.j], &save);
		if ((data->user_input[i.j] == '|' && !save)
			|| !data->user_input[i.j + 1])
		{
			str = ft_substr(data->user_input, i.i, i.j - i.i + 1);
			inputs[i.k++] = ft_cleanstr(str);
			i.i = i.j + 1;
			free(str);
		}
	}
	return (inputs);
}

// parsing de l'input du user
//   1. coupe l'input en fonction des pipes
//   2. set les variables d'environnement
//   3. parse les redirections
//   4. parse la commande et ses arguments
static void	parser(t_data *data)
{
	char	**inputs;
	int		i;
	char	*command;

	if (!data->user_input || !data->user_input[0])
		return ;
	inputs = cut_inputs(data);
	i = -1;
	while (++i != data->command_count)
	{
		command = parse_redirection(data, set_env_command(data, inputs[i]), i);
		parse_command(data, command, i);
		free(command);
	}
	free(inputs);
}

// Le parsing va permettre de tokeniser l'input en une liste chainee
//  de structure pour faciliter grandement l'executing 
void	parsing(t_data *data)
{
	init_command_list(data);
	parser(data);
	if (DEBUG)
	{
		print_command(data);
		data->process_state = READING_STATE;
		return ;
	}
	if (data->process_state == PARSING_STATE)
		data->process_state = EXECUTING_STATE;
}
