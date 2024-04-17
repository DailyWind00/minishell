/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:28:38 by tuvosyl           #+#    #+#             */
/*   Updated: 2023/11/04 17:41:54 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	ft_format(va_list arg, const char c)
{
	int	ret;

	ret = 0;
	if (c == 'c')
		ret = pr_putchar(va_arg(arg, int));
	else if (c == 's')
		ret = pr_putstr(va_arg(arg, char *));
	else if (c == '%')
		ret = pr_putpourcent();
	else if (c == 'd' || c == 'i')
		ret = pr_d(va_arg(arg, int));
	else if (c == 'u')
		ret = pr_u(va_arg(arg, unsigned int));
	else if (c == 'x')
		ret = pr_hexadecimal(va_arg(arg, unsigned int), 'x');
	else if (c == 'X')
		ret = pr_hexadecimal(va_arg(arg, unsigned int), 'X');
	else if (c == 'p')
		ret += pr_pp(va_arg(arg, void *));
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		ret;
	va_list	arg;

	i = 0;
	ret = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ret += ft_format(arg, str[i + 1]);
			i++;
		}
		else
			ret += pr_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (ret);
}
