/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_in_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:43:53 by mgallais          #+#    #+#             */
/*   Updated: 2024/02/21 09:26:14 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// check if a character is in a string
//    return true if yes and false if no
bool	c_in_str(char c, char *str)
{
	while (str)
	{
		if (c == *str)
			return (true);
		str++;
	}
	return (false);
}
