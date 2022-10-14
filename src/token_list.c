/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_list.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 07:49:09 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/10/14 17:19:05 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*new_token_lst(char *command, int token_type)
{
	t_token	*new_token;
	int		index;
	//int		length;

	new_token = NULL;
	if (!command)
		return (NULL);
	new_token->length = ft_strlen(command);
	new_token = malloc(sizeof(t_token));
	if (!new_token)
		exit_program(R124"Could not create a token\n"RESET, 1);
	new_token->value = (char *)malloc(sizeof((char)command + 1));
	if (!new_token->value)
		exit_program(R124"Could not create a token\n"RESET, 1);
	index = -1;
	while (command[index] <= new_token->length)
	{
		index++;
		new_token->value = &command[index];
	}
	new_token->value[index] = '\0';
	new_token->type = token_type;
	new_token->next = NULL;
	new_token->prev = NULL;
	return (new_token);
}

t_token	*add_new_token_back(t_token *token_node, char *command, int token_type)
{
	t_token	*token_to_add;
	t_token	*curr_token;

	if (!command)
		return (NULL);
	token_to_add = new_token_lst(command, token_type);
	if (!token_to_add)
		exit_program(R124"Could not create a token\n"RESET, 1);
	if (token_node == NULL)
		return (token_to_add);
	curr_token = token_node;
	while (curr_token->next != NULL)
	{
		curr_token = curr_token->next;
	}
	curr_token->next = token_to_add;
	token_to_add->prev = curr_token;
	return (token_node);
}

