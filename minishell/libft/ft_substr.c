/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:36:15 by vsoltys           #+#    #+#             */
/*   Updated: 2023/10/23 11:44:32 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*src;
	size_t	i;

	if (!s)
		return (NULL);
	if ((size_t)start >= ft_strlen(s))
		return (ft_strdup(""));
	src = (char *)s + start;
	if (ft_strlen(src) < len)
		i = ft_strlen(src) + 1;
	else
		i = len + 1;
	if (i > SIZE_MAX)
		return (NULL);
	str = (char *)malloc(sizeof(char) * i);
	if (!str)
		return (NULL);
	ft_strlcpy(str, src, i);
	return (str);
}
