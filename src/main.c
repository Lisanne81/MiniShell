/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 07:43:00 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/10/14 10:21:08 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_mini_data(t_mini_data *input, int argc, char **envp)
{
	input->argc = argc;
	input->envp = envp; // moet iets mee gebeuren...
	input->cmd_input = NULL;
	input->paths = NULL;
}


int	main(int argc, char **argv, char **envp)
{
	t_mini_data	input;
	
	(void)argv;
	// (void)envp;
	if (argc != 1)
		exit_program("Not the right arguments\n", 1);
	init_mini_data(&input, argc, envp);
	prompt_loop(&input);
	return (0);
}
