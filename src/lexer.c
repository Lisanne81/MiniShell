/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 07:48:40 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/11/02 16:37:55 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int 	check_token_type(char *content)
{
	t_etoken	type;
	int			index;
	
	index = 0;
	type = NOTHING;
	printf("content for type [%s]\n", content);
	if (content[index] == '|' && content[index + 1] != '|')
		type = IS_PIPE;
	else if (content[index] == '|' && content[index + 1] == '|')
		type = ERROR;
	else if (content[index] == '<' && content[index + 1] != '<')
		type = IS_REDIRECT_IN;
	else if (content[index] == '>' && content[index + 1] != '>')
		type = IS_REDIRECT_OUT_TRUNC;
	else if (content[index] == '>' && content[index + 1] == '>')
		type = IS_REDIRECT_OUT_APPEND;
	else if (content[index] == '<' && content[index + 1] == '<')
		type = HEREDOC;
	else
		type = IS_WORD;
	return (type);
}

static	t_token	*new_token_node(char *content)
	{
		t_token	*new_input;

		new_input = (t_token*)malloc(sizeof(t_token));
		if (!new_input)
			return (NULL);
		new_input->value = content;
		new_input->type = check_token_type(content);
		printf("[%d] new input type\n", new_input->type);
		return (new_input);
	}

void	lexer_input(t_mini_data *data)
{
	int		index;
	int		operator_count;
	char	**part;
	t_token *token_value;
	char	*str;

	printf(G50"in lexer_input\n"RESET);
	operator_count = count_operator(data->cmd_input);
	str = prep_line(data->cmd_input, operator_count);
	part = NULL;
	token_value = NULL;
	if (str == NULL)
		return ;
	printf("terug in lexer input\n str = [%s]\n", str);
	part = split(str);
	index = 0;
	while (part[index])
	{
		token_value = new_token_node(part[index]);
		printf("[%s]token value\n", token_value->value);
		printf("token type = [%d]\n", token_value->type);
		ft_lstadd_back(&data->token, ft_lstnew((void *)token_value));
		//printf(B23"tokens: [%s]\n"RESET, token[index]);
		index++;
	}
	//free(part);
	//print_list(data->token);
	//printf("[%s]\n", data->token->(t_token *)content);
	return ;
}

// void	lexer(t_mini_data *input)
// {
// 	int		index;
// 	char	*result;
// 	int		len;

// 	len = ft_strlen(input->cmd_input);
// 	index = 0;
// 	result = input->cmd_input;
// 	while (result[index])
// 	{
// 		printf(B17"LINE: [%c]------[%d]\n"RESET, result[index], index);
// 		index++;
// 	}
// 	lexer_input(result, input);
// 	//free(tokens);
// }

// static char	**lexer_input(char *input)
// {
// 	int		index;
// 	int		operator_count;
// 	char	**token;
// 	char	*str;

// 	printf(G50"in lexer_input\n"RESET);
// 	operator_count = count_operator(input);
// 	str = prep_line(input, operator_count);
// 	token = NULL;
// 	if (str == NULL)
// 	{
// 		return (NULL);
// 	}
// 	index = 0;
// 	printf("terug in lexer input\n str = [%s]\n", str);
// 	token = split(str);
// 	// while (token[index])
// 	// {
// 	// 	printf(B23"tokens: [%s]\n"RESET, token[index]);
// 	// 	index++;
// 	// }
// 	return (token);
// }

// void	lexer(t_mini_data *input)
// {
// 	int		index;
// 	char	*result;
// 	char	**tokens;
// 	//t_token *input;
// 	int		len;

// 	len = ft_strlen(input->cmd_input);
// 	index = 0;
	
// 	result = input->cmd_input;
// 	printf("len[%d]\n", len);
// 	while (result[index])
// 	{
// 		printf(B17"LINE: [%c]------[%d]\n"RESET, result[index], index);
// 		index++;
// 	}
// 	printf("[%s]\n", result);
// 	printf("[%c]last of line\n", result[index]);
// 	tokens = lexer_input(result);
// 	index = 0;
// 	while (tokens[index])
// 	{
// 		ft_lstadd_back(&input->token, ft_lstnew(tokens[index]));
// 		printf(B23"tokens: [%s]\n"RESET, tokens[index]);
// 		index++;
// 	}
// 	print_list(input->token);
// 	free(tokens);
// }

