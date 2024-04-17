/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:41:27 by vsoltys           #+#    #+#             */
/*   Updated: 2023/10/23 16:46:39 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n )
{
	char	*str;
	char	chara;
	size_t	i;

	i = 0;
	chara = (char)c;
	str = (void *)s;
	while (i != n)
	{
		if (str[i] == chara)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
