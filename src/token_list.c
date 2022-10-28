/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_list.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 07:49:09 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/10/18 16:24:43 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
// t_token	init_new_token(t_token *new_token)
// {
// 	new_token->id = 0;
// 	new_token->length = 0;
// 	new_token->type = 0;
// 	new_token->value = NULL;
// 	return (*new_token);
// }

t_token	*new_token_lst(char *command, int token_type)
{
	t_token	*new_token;
	int		index;
	//int		length;
	printf("in new token list\n");
	printf("command[%s], token_type[%d]\n", command, token_type);
	
	new_token = NULL;
	index = ft_strlen(command);
	// if (!command)
	// 	return (NULL);
	//new_token->length = ft_strlen(command);
	printf("strl command[%d]\n", index);
	
	new_token = malloc(sizeof(t_token));
	if (!new_token)
		exit_program(R124"Could not create a token\n"RESET, 1);
	new_token->value = (char *)malloc(sizeof((char)index + 1));
	if (!new_token->value)
		exit_program(R124"Could not create a token\n"RESET, 1);
	index = 0;
	while (command[index])
	{
		new_token->value[index] = command[index];
		index++;
	}
	new_token->value[index] = '\0';
	new_token->type = token_type;
	new_token->next = NULL;
	//new_token->prev = NULL;
	printf("token list value [%s]\n", new_token->value);
	return (new_token);
}

t_token	*add_new_token_back(t_token *token_node, char *command, int token_type)
{
	t_token	*token_to_add;
	t_token	*curr_token;
	printf("in add new token\n");
	printf("command[%s], token_type[%d], token_node[%p]\n", command, token_type, token_node);
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
