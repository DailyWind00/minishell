/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:42:08 by vsoltys           #+#    #+#             */
/*   Updated: 2023/10/16 12:42:09 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	result;

	result = ft_strlen(src);
	i = 0;
	if (!dst || !src)
		return (0);
	if (size != 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (result);
}

size_t	ft_strncpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	result;

	result = ft_strlen(src);
	i = 0;
	if (!dst || !src)
		return (0);
	if (size != 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (result);
}

/*int main() {
    char source[] = "Bonjour, monde !";
    char destination[20]; 

    strlcpy(destination, source, sizeof(destination));

    printf("Chaîne copiée : %s\n", destination);

    return 0;
}*/
