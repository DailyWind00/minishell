/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exepitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:03:18 by vsoltys           #+#    #+#             */
/*   Updated: 2024/02/20 15:18:22 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	cnombre(long n_l, int sign)
{
	unsigned int	nb_digit;

	if (n_l == 0)
		return (1);
	nb_digit = 0;
	while (n_l > 0)
	{
		n_l /= 10;
		nb_digit++;
	}
	if (sign == -1)
		nb_digit++;
	return (nb_digit);
}

static void	convert_nb(char *outstr, long n_l, unsigned int nb_digit,
		int sign)
{
	outstr[nb_digit] = '\0';
	outstr[--nb_digit] = n_l % 10 + '0';
	n_l /= 10;
	while (n_l > 0)
	{
		outstr[--nb_digit] = n_l % 10 + '0';
		n_l /= 10;
	}
	if (sign == -1)
		outstr[0] = '-';
}

char	*ft_uitoa(unsigned int n)
{
	char			*outstr;
	long			n_l;
	unsigned int	nb_digit;

	n_l = n;
	nb_digit = cnombre(n_l, 1);
	outstr = malloc(sizeof(char) * (nb_digit + 1));
	if (!outstr)
		return (NULL);
	convert_nb(outstr, n_l, nb_digit, 1);
	return (outstr);
}
