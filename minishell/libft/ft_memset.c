/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:50:19 by vsoltys           #+#    #+#             */
/*   Updated: 2023/10/23 16:35:17 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cpointer;

	cpointer = (unsigned char *)s;
	i = 0;
	while (i != n)
	{
		cpointer[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
