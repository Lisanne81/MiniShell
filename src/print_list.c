/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_list.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 14:40:15 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/11/02 15:52:48 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_list(t_list *tokens)
{
	t_list	*current;
	int		index;
	int		color;

	color = 16;
	index = 1;
	current = tokens;
	if (tokens == NULL)
		printf("SHIT! no list to print\n");
	//printf("PRINT_list length of line = [%d]\n", length);
	printf("the list...: \n");
	while (current != NULL)
	{
		
		printf("\033[48;5;%im[%s]\t[%d]\n\033[m", color, \
			((t_token *)current->content)->value,  \
				((t_token *)current->content)->type);
		current = current->next;
		index++;
		color++;
	}
}
