/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:51:33 by tuvosyl           #+#    #+#             */
/*   Updated: 2023/11/04 17:43:28 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

int		pr_pp(void *ptr);
int		pr_putchar(char c);
int		ft_printf(const char *str, ...);
int		ft_format(va_list arg, const char c);
int		pr_putstr(char *str);
int		pr_putpourcent(void);
char	*ft_itoa(int n);
int		pr_d(int a);
char	*ft_uitoa(unsigned int n);
int		pr_u(unsigned int a);
int		pr_hexadecimal(unsigned int x, char x_or_x);

#endif