/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:56:23 by vsoltys           #+#    #+#             */
/*   Updated: 2023/10/23 16:45:28 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy( void *dest, const void *src, size_t n )
{
	size_t		i;
	char		*res;
	const char	*sour;

	res = (char *)dest;
	sour = (char *)src;
	i = 0;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (i != n)
	{
		res[i] = sour[i];
		i++;
	}
	return (res);
}
