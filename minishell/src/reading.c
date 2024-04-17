/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:55:31 by mgallais          #+#    #+#             */
/*   Updated: 2024/04/12 16:15:47 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Le reading utilise la fonction readline pour lire les inputs
//  que le user veut utiliser
void	reading(t_data *data)
{
	data->user_input = readline("\033[31;1mƐ>\033[0m ");
	if (!data->user_input)
	{
		data->process_state = BREAK_STATE;
		return ;
	}
	add_history(data->user_input);
	data->process_state = CHECKING_STATE;
}
