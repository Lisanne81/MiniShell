/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 07:43:26 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/11/02 16:27:42 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <stdbool.h>
//# include <signal.h>
//# include <sys/wait.h>

# define R124 "\e[38;5;196m"
# define B17 "\e[38;5;202m"
# define B18 "\e[38;5;209m"
# define B19 "\e[38;5;214m"
# define B20 "\e[38;5;216m"
# define B21 "\e[38;5;21m"
# define G22 "\e[38;5;22m"
# define B23 "\e[38;5;23m"
# define Y185 "\e[38;5;185m"
# define G40 "\e[38;5;40m"
# define G41 "\e[38;5;41m"
# define G42 "\e[38;5;42m"
# define G43 "\e[38;5;43m"
# define G46 "\e[38;5;46m"
# define G47 "\e[38;5;47m"
# define G48 "\e[38;5;48m"
# define G49 "\e[38;5;49m"
# define G50 "\e[38;5;50m"
# define RESET "\e[0m"

# define SPACE ' '
//# define WORD 1
// # define NEW_LINE "\n"
// # define DOUBLE_QUOTES '"'
// # define SINGLE_QUOTES '\''

typedef enum e_token
{
	NOTHING,
	IS_PIPE,
	IS_REDIRECT_IN,
	IS_REDIRECT_OUT_TRUNC,
	IS_REDIRECT_OUT_APPEND,
	HEREDOC,
	ERROR,
	IS_WORD
}	t_etoken;
typedef enum quote
{
	NONE,
	SINGLE,
	DOUBLE,
	BACKSLASH,
	END
}	t_quote;

typedef struct s_token
{
	char			*value;
	t_etoken		type;
}	t_token;
typedef struct s_mini_data
{
	char			*cmd_input;
	char			**argv;
	char			**envp;
	char			**paths;
	int				argc;
	t_token			*token_lst;
	t_list			*token;
}	t_mini_data;
//struct for PID?

/* enum tokens */
/* command list*/

int		exit_program(char *message, int id);
void	prompt_loop(t_mini_data *input);
void	lexer(t_mini_data *input);
void	lexer_input(t_mini_data *data);
int		count_quote(char *line, char c);
int		found_operator(char *line, int index);
int		count_operator(char *input);
void	isolate_operater(char *new_line, char *line, int *temp, int *index);
char	*prep_line(char *line, int operator_count);
char	 **split(char *str);
void	print_list(t_list *tokens);
t_token	*new_token_lst(char *command, int token_type);
void	delete_token_list(void *content);


#endif