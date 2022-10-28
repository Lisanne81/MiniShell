/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/06 12:12:51 by lhoukes       #+#    #+#                 */
/*   Updated: 2021/03/09 09:54:15 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_input;

	new_input = (t_list*)malloc(sizeof(t_list));
	if (!new_input)
		return (NULL);
	new_input->content = content;
	new_input->next = NULL;
	return (new_input);
}
