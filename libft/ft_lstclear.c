/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/08 18:51:50 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/11/02 16:24:11 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*element;

	if (!*lst || !del)
		return ;
	while (*lst)
	{
		element = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = element;
	}
	*lst = NULL;
}
