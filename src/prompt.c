/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prompt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 07:48:55 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/11/02 16:27:22 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	prompt_loop(t_mini_data *input)
{
	while ("the world turns")
	{
		printf(" in prompt loop\n");
		input->cmd_input = readline(Y185"🐌mini🐚$ "RESET);
		if (input->cmd_input == NULL)
			exit_program("somthing went wrong\n", 1);
		if (input->cmd_input)
		{
			add_history(input->cmd_input);
		}
		lexer_input(input);
		print_list(input->token);
		ft_lstclear(&input->token, delete_token_list);
	}
}