/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exep1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:02:31 by tuvosyl           #+#    #+#             */
/*   Updated: 2023/11/04 13:01:43 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pr_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	pr_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		pr_putstr("(null)");
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	pr_putpourcent(void)
{
	write (1, "%", 1);
	return (1);
}

int	pr_d(int a)
{
	char	*str;

	str = ft_itoa(a);
	a = pr_putstr(str);
	free(str);
	return (a);
}

int	pr_u(unsigned int a)
{
	char	*str;

	str = ft_uitoa(a);
	a = pr_putstr(str);
	free(str);
	return (a);
}
