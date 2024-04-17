/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:03:56 by vsoltys           #+#    #+#             */
/*   Updated: 2023/10/23 16:41:02 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		if (ft_strncmp((char *)&big[i], little, ft_strlen(little)) == 0)
		{
			if (i + ft_strlen(little) > len)
				return (NULL);
			return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
