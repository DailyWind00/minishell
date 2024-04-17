/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:02:05 by vsoltys           #+#    #+#             */
/*   Updated: 2024/02/19 14:45:27 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int	cdebut(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len && ft_strchr(set, s1[i]) != NULL)
	{
		i++;
	}
	return (i);
}

static int	cfin(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len && ft_strchr(set, s1[len - i - 1]) != NULL)
	{
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char *s1, char const *set)
{
	int		debut;
	int		fin;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	debut = cdebut(s1, set);
	fin = cfin(s1, set);
	if (fin <= debut)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (fin - debut + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + debut, fin - debut + 1);
	free(s1);
	return (str);
}

/*int main()
{
    const char *s1 = "   lorem ipsum dolor sit amet   ";
    const char *set = " ";
    char *trimmed_str = ft_strtrim(s1, set);

    if (trimmed_str)
    {
        printf("Chaîne originale: \"%s\"\n", s1);
        printf("Chaî \"%s\"\n", trimmed_str);

        // N'oubliez pas de libérer la mémoire allouée
        free(trimmed_str);
    }
    else
    {
        printf("Erreu arguments invalides.\n");
    }

    return 0;
}*/