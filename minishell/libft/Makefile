NAME = libft.a

BONUS = ft_lstmap.c ft_lstiter.c ft_lstlast.c ft_lstsize.c ft_lstadd_front.c ft_lstnew.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c
LIBC = ${BONUS} del_char.c is_env.c ft_remove_from_str.c is_quote.c rm_char_str.c ft_strsplit.c c_in_str.c is_bracket.c is_whitespace.c is_chevron.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c get_next_line_utils.c ft_putstr.c printf.c exep1.c exepitoa.c exepx.c

SRCS = ${LIBC}
SRCSALL = ${LIBC} ${BONUS}

OBJS = ${SRCS:.c=.o}
OBJSALL = ${SRCSALL:.c=.o} 

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I ./

all: 	${NAME}

.c.o:
		@printf "\033[0;33m\t| Compilation de %-33.33s\r\e[0m" $@
		@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		@ar -rsc ${NAME} ${OBJS}
		@printf "\033[1;92m\t|  >>> Libft compiled                                       \n\n\033[0m"

bonus:	${OBJSALL}
		@ar -rsc ${NAME} ${OBJSALL}

clean:	
		@rm -f ${OBJSALL}
		@printf "\033[1;31m- [LIBFT] Object files deleted\n\033[0m"

fclean:	clean;
		@rm -f ${NAME}
		@printf "\033[1;31m- [LIBFT] Static library file deleted\n\033[0m"

re:	fclean all
