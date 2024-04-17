/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoltys <vsoltys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:14:08 by mgallais          #+#    #+#             */
/*   Updated: 2024/04/12 18:14:23 by vsoltys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*###########################################################################*/
/*                                  Defines                                  */
/*###########################################################################*/
// Debug mode (compile with make debug)
# ifndef DEBUG
#  define DEBUG 0
# else
#  define DEBUG 1
# endif

// Process status
# define BREAK_STATE     0
# define READING_STATE   1
# define CHECKING_STATE  2
# define PARSING_STATE   3
# define EXECUTING_STATE 4

// Redirection
# define SINGLE_OUTPUT  1 //>
# define DOUBLE_OUTPUT  2 //>>
# define SINGLE_INPUT   3 //<
# define DOUBLE_INPUT   4 //<<

// Custom defines
# define WHITESPACES "\t\n\v\f\r "
/*###########################################################################*/
/*                                 Includes                                  */
/*###########################################################################*/
# include "../libft/libft.h"
# include <stdbool.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <string.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <dirent.h>
# include <unistd.h>

/*###########################################################################*/
/*                                Structures                                 */
/*###########################################################################*/
// Stock 3 integers, can be used for anything
typedef struct s_3int
{
	int		i;
	int		j;
	int		k;
}	t_3int;

// For the redirection of the command in the s_command struct
typedef struct s_redir
{
	int					redir;
	char				*file;
}	t_redir;

// From parsing for executing
typedef struct s_command
{
	char				**command;
	int					argument_count;
	t_redir				*redir;
	int					redir_count;
}	t_command;

// For environment
typedef struct s_env
{
	struct s_env		*previous;
	struct s_env		*next;
	char				*name;
	char				*value;
}	t_env;

// Main structure
typedef struct s_data
{
	t_command	*command;
	int			command_count;
	t_env		*env;
	char		**oui;
	char		*user_input;
	int			pipefd[2];
	int			process_state;
}	t_data;

/*###########################################################################*/
/*                                Prototypes                                 */
/*###########################################################################*/
// Init minishell
void		set_signal(void);
void		set_signal2(void);

// t_env list
void		env_to_list(char *env[], t_env **env_out);
t_env		*ft_lstnew_name(char *content);
char		*value_by_name(t_env **env, char *name);
char		*value_by_name_original(t_env **env, char *name);
void		ft_envadd_back(t_env **lst, t_env *new);
t_env		*ft_envlast(t_env *lst);
void		free_env(t_env *env_list);

// Reading
void		reading(t_data *data);

// Checking
void		checking(t_data *data);
bool		check_quote(char *str);
bool		check_pipe(char *str);
bool		check_chevron(char *str);

// Parsing
void		parsing(t_data *data);
void		init_command_list(t_data *data);
void		parse_command(t_data *data, char *command, int current_command);
char		*set_env_command(t_data *data, char *str);
char		*parse_redirection(t_data *data, char *input, int current_command);
char		*clean_redir(char *str);
void		free_command_list(t_data *data);
void		quote_saver(char c, char *save);
char		**split_quote(char *str);
char		*remove_quotes(char *str);
int			alloc_env_command(t_data *data, char *str);
bool		is_heredoc(char *str, int i);

// Executing
int			tcheck_command(t_data *data, int i, int pipe_state);
void		executing(t_data *data);
char		*find_cmd_path(char *str, t_data *data);
void		execute_pipeline(t_data *data);
int			free_things(t_data *data, char *tokens);
void		free_split(char **table);
char		**c_split(char const *s, char c);
int			redir_1(t_data *data, int i, int j);
int			redir_2(t_data *data, int i, int j);
int			redir_3(t_data *data, int i, int j);
char		*redir_4(t_data *data, int i, int j, char *temp);
char		**redir_4_while(char *temp, int i);
int			free_redir4(int i);
int			redir_aled(int i, int *state, char **table, char *str);
int			redir_4_2(t_data *data);
void		tcheck_redir_4(t_data *data);
int			tcheck_equal(char *input);
int			export_command1_2(t_data *data, char **token, int i, t_env *temp);
int			export_command2(char *input, t_env *temp, t_data *data);
void		free_double(t_data *data, char *cmd_path);
char		*ec3v2(int i, char *input);

// Builtins
int			unset_command(t_data *data, char **token);
int			pwd_command(char **tokens);
int			cd_command(t_data *data, char **token);
int			echo_command(char **token);
int			exit_command(t_data *data, char **token, int cmd_count);
int			export_command(t_data *data, char **token);
int			ls_command(t_data *data, char **token);
int			env_command(t_data *data);
int			clear_command(void);
int			ls_command_pipe(t_data *data, char **token);
int			export_valid_string(char *token);
t_env		*export_command3(int i, char *input, t_env *temp);
void		free_command_list_redir(t_data *data);

#endif
