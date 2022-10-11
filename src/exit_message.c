/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_message.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 07:52:50 by lhoukes       #+#    #+#                 */
/*   Updated: 2022/10/11 10:45:00 by lhoukes       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

int	exit_program(char *message, int id)
{
	if (id == 0)
	{
		ft_putstr_fd(message, 1);
		exit(0);
	}
	else if (id == 1)
	{
		ft_putstr_fd(R124"ERROR\n"RESET, 1);
		ft_putstr_fd(message, 1);
		exit(1);
	}
	return (0);
}

// void	free_map(t_map *map)
// {
// 	t_map	*temp;

// 	if (map == NULL)
// 		return ;
// 	while (map != NULL)
// 	{
// 		temp = map;
// 		map = map->next;
// 		free(temp);
// 	}
// }
