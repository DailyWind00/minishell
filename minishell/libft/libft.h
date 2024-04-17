/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:40:44 by blebas            #+#    #+#             */
/*   Updated: 2024/03/29 12:10:09 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdbool.h>

# define FD_LIMIT 1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2000
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

char	*del_char(char *str, char *set);
bool	is_env(char c);
size_t	ft_strncpy(char *dst, const char *src, size_t size);
bool	is_quote(char c);
char	*rm_char_str_quote(char *str, char *set);
char	*rm_char_str(char *str, char *set);
char	*get_next_line(int fd);
char	*ft_strndup(const char *s, size_t n);
char	**ft_strsplit(char const *s, char *c);
bool	c_in_str(char c, char *str);
int		is_whitespace(char c);
int		is_chevron(char c);
int		is_bracket(char c);
size_t	ft_strleny(const char *s);
char	*ft_strchry(char *s, int c);
char	*ft_strjoiny(char *s1, char *s2);
char	*ft_strcpyy(char *dst, const char *src);
char	*get_next_line(int fd);
int		pr_pp(void *ptr);
int		pr_putchar(char c);
int		ft_printf(const char *str, ...);
int		ft_format(va_list arg, const char c);
int		pr_putstr(char *str);
int		pr_putpourcent(void);
int		pr_d(int a);
char	*ft_uitoa(unsigned int n);
int		pr_u(unsigned int a);
int		pr_hexadecimal(unsigned int x, char x_or_x);
void	*ft_memdupp(const void *src, size_t n);
void	*ft_memcpyp(void *dest, const void *src, size_t n);
char	*get_next_line(int fd);
char	*ft_strcpyy(char *dst, const char *src);
int		ft_atoi(const char *nptr);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_str_rmv_char(char *str, char c);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
#endif
