/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 07:48:40 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/10/14 17:15:52 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*add_new_token_back(t_token *token_node, char *command, int token_type);

int	is_special(char c)
{
	if (c != '|' && c != '&' && c != '<' && c != '>')
		return (1);
	return (0);
}

int	command_len(char *command, int offset)
{
	int		length;
	char	c;

	length = 0;
	while (command[offset] && is_special(command[offset]) == 1)
	{
		if (command[offset] == '"' || command[offset] == '\'')
		{
			c = command[offset];
			offset++;
			length++;
			while (command[offset] && command[offset] != c)
			{
				offset++;
				length++;
			}
		}
		length++;
		offset++;
	}
	return (length);
}

int	is_word(t_mini_data *input, int offset)
{
	char	*command;
	//char	*sign;
	//int		length;
	

	command = ft_substr(input->cmd_input, offset, command_len(input->cmd_input, offset));
	offset = offset + command_len(input->cmd_input, offset);
	input->token_lst = add_new_token_back(input->token_lst, command, WORD);
	
	// while (input->cmd_input[index])
	// {
	// 	printf(B17"LINE: [%c]\n", input->cmd_input[index]);
    //  	index++;
	// 	//printf("[%d]history\n", add_history(input->cmd_input));
	// } 
	free(command);
	return (offset);
}

void	lexer(t_mini_data *input)
{
	int		index;
	//t_token	*token;

	index = 0;
	input->cmd_input = *ft_split(input->cmd_input, ' ');
	while (input->cmd_input[index])
	{
		printf(B17"LINE: [%c]\n", input->cmd_input[index]);
     	index++;
		//printf("[%d]history\n", add_history(input->cmd_input));
	} 
	printf("[%d]history\n", add_history(input->cmd_input));
	index = 0;
	while (input->cmd_input[index])
	{
		while (input->cmd_input[index] == SPACE)
		{
			index++;
			if (input->cmd_input[index] != '&' && input->cmd_input[index] != '|' \
			&& input->cmd_input[index] != '<' &&  input->cmd_input[index] != '>') 
				index = is_word(input, index);
		}
	}
}
