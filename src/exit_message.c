/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_message.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 07:52:50 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/11/02 16:28:29 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

int	exit_program(char *message, int id)
{
	if (id == 0)
	{
		ft_putstr_fd(message, 1);
		exit(0);
	}
	else if (id == 1)
	{
		ft_putstr_fd(R124"ERROR\n"RESET, 1);
		ft_putstr_fd(message, 1);
		exit(1);
	}
	return (0);
}

void	delete_token_list(void *content)
{
	t_token	*token;

	token = (t_token *)content;
	free(token->value);
	//free(token->type);// hoe deze te verwijderen?
	free(content);
	content = NULL;
}
