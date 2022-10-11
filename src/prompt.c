/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prompt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 07:48:55 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/10/11 11:40:12 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	unclose_quote(char	*str)
{
	int		i;
	t_quote	quote;

	i = 0;
	quote = NONE;
	printf("[%s] quote quote\n", str);
	while (str[i])
	{
		if (str[i] == '"')
		{
			if (quote == NONE)
				quote = DOUBLE;
			else if (quote == DOUBLE)
				quote = NONE;
		}
		if (str[i] == '\'')
		{
			if (quote == NONE)
				quote = SINGLE;
			else if (quote == SINGLE)
				quote = NONE;
		}
		i++;
	}
	return (quote);
}

int	pars(char *str, t_command **cmd_line)
{
	int	output;

	output = unclose_quote(str);
	if (output > 0)
	{
		write(2, "minishell: miss quote\n", 22);
		free(cmd_line);
	}
	// else
	// {
	// 	if (get_cmd_line(str, cmd_line) > 0)
	// 		return (free_str_all_ret_malloc_error(cmd_line, str));
	// 	if (split_all_cmdl_string_to_token(cmd_line) > 0)
	// 		return (free_str_all_ret_malloc_error(cmd_line, str));
	// 	output = expend_words(cmd_line);
	// 	if (output != 0)
	// 	{
	// 		free_all(cmd_line);
	// 		if (output == 50)
	// 			return (free_str_ret_malloc_error(str));
	// 	}
	// 	if (organise_arg(cmd_line) != 0)
	// 		return (free_str_all_ret_malloc_error(cmd_line, str));
	// }
	return (output);
}


void operate_on_line(t_command **cmd_line, char *line)
{
	int	output;

	output = pars(line, cmd_line);
	printf("work in progress\n");
	
	// if (output == 0)
	// {
	// 	if (str != NULL && *cmd_line != NULL)
	// 	{
	// 		output = ft_exec(cmd_line);
	// 		if (output != 0)
	// 		{
	// 			//free_all_error(cmd_line, str, output);
	// 			exit (1);
	// 		}
	// 	}
	// }
}

void	prompt_loop()
{
	char		*line;
	t_command	*cmd_line;
	int			status;
	int			index;

	line = NULL;
	status = 1;

	while ("the world turns")
	{
		// I guess this reads from the prompt:
		line = readline(Y185"🐌mini🐚$ ");
		index = 0;
		if (line == NULL)
			exit_program("somthing went wrong\n", 1);
		else
			operate_on_line(&cmd_line, line);
		//cmd_line = split(line);
		// while (commands[index] != NULL)
		// {
		// 	printf(B17"LINE: [%s]\n", commands[index]);
     	// 	index++;
		// } 
		// printf("[%d]history\n", add_history(line));
		free(line);
	} 
 
	while (status)
	{
		
	}
	//return ();
}