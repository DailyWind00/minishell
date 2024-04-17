NAME 		= minishell
CC 			= cc
RM			= rm -f

CFLAGS 		+= -g -Wall -Wextra -Werror
FT			= libft
LIBFT		= $(FT)/libft.a
DEBUG		= 0

SRC		=	src/t_env_struct.c \
			src/signals.c \
			src/reading.c \
			src/main.c \
			src/env_to_list.c \
			src/parsing/parsing_clean_redir.c \
			src/parsing/parsing_command.c \
			src/parsing/parsing_env_part2.c \
			src/parsing/parsing_env.c \
			src/parsing/parsing_init.c \
			src/parsing/parsing_redirection.c \
			src/parsing/parsing_utils.c \
			src/parsing/parsing.c \
			src/executing/custom_split.c \
			src/executing/executing.c \
			src/executing/main_executing.c \
			src/executing/path.c \
			src/executing/redir.c \
			src/executing/redir2.c \
			src/executing/utils.c \
			src/executing/builtins/command_cd_pwd.c \
			src/executing/builtins/command_echo.c \
			src/executing/builtins/command_exit.c \
			src/executing/builtins/command_export.c \
			src/executing/builtins/command_export2.c \
			src/executing/builtins/command_ls.c \
			src/executing/builtins/command_unset.c \
			src/checking/checking_chevron.c \
			src/checking/checking_pipe.c \
			src/checking/checking_quote.c \
			src/checking/checking.c
OBJ		= $(SRC:.c=.o)

all:
	@printf "\033[1;36m\nStarting minishell compilation\n\e[0m"
	@make -s redirect

redirect: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) -lreadline
	@printf "\033[1;92m >>> Minishell compiled                                                     \n\n\033[0m"
	
$(LIBFT): $(FT)
	@printf "\033[1;35m\n\t| Starting libft compilation\n\e[0m"
	@make -s -C $(FT)

%.o: %.c
	@printf "\033[0;33mCompilation de %-33.33s\r\e[0m" $@
	@if [ $(DEBUG) -eq 1 ]; then $(CC) $(CFLAGS) -c $< -o $@ -D DEBUG=1; else $(CC) $(CFLAGS) -c $< -o $@; fi

clean:
	@$(RM) $(OBJ)
	@if [ -d "$(FT)" ]; then make -s fclean -C $(FT); fi
	@$(RM) $(LIBFT)
	@printf "\033[1;31m- Object files deleted\n\033[0m"

fclean: clean	
	@$(RM) $(NAME)
	@printf "\033[1;31m- Executable file deleted\n\033[0m"

re: fclean all

test:
	@make -s re
	@make -s clean
	@clear
	@echo "\033[1;92mDONE !"

norminette:
	@clear
	@sh ~/better_norminette.sh

debug: fclean
	@make -s DEBUG=1 all
	@make clean
	@clear

.PHONY: all redirect clean fclean re ft test norminette debug
