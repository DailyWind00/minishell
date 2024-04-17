/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exepx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:06:25 by vsoltys           #+#    #+#             */
/*   Updated: 2023/11/04 17:42:00 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pr_hexadecimal(unsigned int x, char x_or_x)
{
	char	string[25];
	char	*base_character;
	int		i;
	int		j;

	if (x_or_x == 'X')
		base_character = "0123456789ABCDEF";
	else
		base_character = "0123456789abcdef";
	i = 0;
	if (x == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	while (x != 0)
	{
		string[i] = base_character [x % 16];
		x = x / 16;
		i++;
	}
	j = i;
	while (j--)
		write (1, &string[j], 1);
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_baseseize(unsigned long nb, char *base)
{
	if (nb / 16)
		ft_baseseize(nb / 16, base);
	ft_putchar(base[nb % 16]);
}

static int	ft_sizehex(unsigned long nb)
{
	int	size;

	size = 0;
	while (nb != 0)
	{
		size++;
		nb /= 16;
	}
	return (size);
}

int	pr_pp(void*ptr)
{
	unsigned long	addptr;

	addptr = (unsigned long) ptr;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	pr_putstr("0x");
	ft_baseseize(addptr, "0123456789abcdef");
	return (ft_sizehex(addptr) + 2);
}
