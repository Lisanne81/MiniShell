/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/08 18:51:50 by lhoukes       #+#    #+#                 */
/*   Updated: 2021/03/09 09:53:42 by lhoukes       ########   odam.nl         */
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
