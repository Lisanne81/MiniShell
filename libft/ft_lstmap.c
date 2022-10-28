/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/12 10:26:03 by lhoukes       #+#    #+#                 */
/*   Updated: 2021/03/09 09:54:07 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_input;

	if (lst == NULL || *f == NULL)
		return (NULL);
	new_list = 0;
	while (lst)
	{
		new_input = ft_lstnew(f(lst->content));
		if (new_input == 0)
			ft_lstclear(&new_list, del);
		ft_lstadd_back(&new_list, new_input);
		lst = lst->next;
	}
	return (new_list);
}
