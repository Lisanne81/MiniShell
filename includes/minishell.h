/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 07:43:26 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/10/11 11:31:47 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include "./libft/libft.h"
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


# define NEW_LINE "\n"
# define DOUBLE_QUOTES '"'
# define SINGLE_QUOTES '\''

typedef struct s_command
{
	char				*cmd_line;
	struct s_command	*next;
}						t_command;

typedef enum e_token
{
	WORD,
	FILE_IN,
	FILE_OUT,
	PWD,
	IS_PIPE,
	IS_REDIRECT_IN,
	IS_REDIRECT_OUT,
	IS_ENVP,
}	t_tolken;

typedef enum quote
{
	NONE,
	SINGLE,
	DOUBLE,
	BACKSLASH,
	END
}	t_quote;
//struct for PID?

/* enum tokens */
/* command list*/

int	exit_program(char *message, int id);
void	prompt_loop();

#endif
