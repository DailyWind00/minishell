/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:12:03 by mgallais          #+#    #+#             */
/*   Updated: 2024/04/11 15:56:40 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern int	g_last_signal_id;

// Le checking permet de verifier qu'il n'y a pas de brackets ouverts
//  ou trop de pipe qui s'enchaine dans l'input de l'user
//  ou des chevrons mal places
void	checking(t_data *data)
{
	if (check_quote(data->user_input)
		|| check_pipe(data->user_input)
		|| check_chevron(data->user_input))
	{
		data->process_state = READING_STATE;
		write(2, " invalid command\n", 17);
		g_last_signal_id = 2;
	}
	else
		data->process_state = PARSING_STATE;
}
