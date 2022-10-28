/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@/Users/lhoukes/Desktop/libft_2021/libftversion300/ft_lstiter.cstudent.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/08 10:13:15 by lhoukes       #+#    #+#                 */
/*   Updated: 2021/03/09 09:54:01 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
