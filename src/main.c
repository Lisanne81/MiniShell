/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 07:43:00 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/10/11 10:57:26 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	
	(void)argv;
	(void)envp;
	if (argc != 1)
		exit_program("Not the right arguments\n", 1);
	prompt_loop();
	return (0);
}
