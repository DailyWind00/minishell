/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:42:21 by vsoltys           #+#    #+#             */
/*   Updated: 2024/02/20 16:56:15 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(ft_strlen(s) + 1 * sizeof(*s));
	i = 0;
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	char	*dst;

	len = 0;
	while (len < n && s[len])
		len++;
	dst = malloc(len + 1);
	if (dst)
		ft_strlcpy(dst, s, len + 1);
	return (dst);
}
