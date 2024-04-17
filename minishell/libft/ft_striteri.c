/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:02:23 by vsoltys           #+#    #+#             */
/*   Updated: 2023/10/21 12:08:29 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = ft_strlen((const char *)s);
	if (s != NULL && f != NULL)
	{
		while (i < j)
		{
			f(i, s);
			i++;
			s++;
		}
	}
}
