/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prompt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 07:48:55 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/10/28 09:09:00 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	operate_on_line(t_mini_data *input)
{
	printf(" in operate on line\n");
	// if (count_quote(input->cmd_input, '\"') != 0)
	// 	exit_program("oneven quotes\n", 1);
	// if (count_quote(input->cmd_input, '\'') != 0)
	// 	exit_program("oneven quotes\n", 1);
	printf("we gaan door\n");
	lexer(input);
}

void	prompt_loop(t_mini_data *input)
{
	while ("the world turns")
	{
		printf(" in prompt loop\n");
		input->cmd_input = readline(Y185"🐌mini🐚$ "RESET);
		if (input->cmd_input == NULL)
			exit_program("somthing went wrong\n", 1);
		if (input->cmd_input)
			add_history(input->cmd_input);
		operate_on_line(input);
		printf(G42"input[%s]\n"RESET, input->cmd_input);
	}
}