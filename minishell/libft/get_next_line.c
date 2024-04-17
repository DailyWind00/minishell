/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:40:19 by vsoltys           #+#    #+#             */
/*   Updated: 2023/12/01 13:58:51 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

static char	*get_line(char *next_line)
{
	int		i;
	char	*str;

	i = 0;
	if (!next_line[i])
		return (NULL);
	while (next_line[i] != '\n' && next_line[i])
		i++;
	str = (char *)malloc(sizeof(char) * i + 2);
	if (!str)
		return (NULL);
	str = ft_strcpyy(str, next_line);
	return (str);
}

char	*rread(int fd, char *next_line)
{
	char	*buffer;
	int		i;

	buffer = (char *)malloc (sizeof(char) * (BUFFER_SIZE + 1));
	i = 1;
	if (!buffer)
		return (NULL);
	while (ft_strchry(next_line, '\n') == NULL && i != 0)
	{
		i = read (fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(next_line);
			free (buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		next_line = ft_strjoiny(next_line, buffer);
	}
	free (buffer);
	return (next_line);
}

static char	*ft_save(char *next_line)
{
	int		i;
	char	*str;
	int		j;

	i = 0;
	while (next_line[i] && next_line[i] != '\n')
		i++;
	if (!next_line[i])
	{
		free(next_line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strleny(next_line) - i + 1));
	if (!str)
		return (NULL);
	j = 0;
	i++;
	while (next_line[i])
		str[j++] = next_line[i++];
	str[j] = '\0';
	free (next_line);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	next_line = rread(fd, next_line);
	if (!next_line)
		return (NULL);
	str = get_line(next_line);
	next_line = ft_save(next_line);
	return (str);
}
