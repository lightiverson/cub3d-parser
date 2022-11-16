/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_breezy.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 18:37:22 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/16 18:37:46 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_splitted_array(char **splitted_array)
{
	int	i;

	i = 0;
	while (splitted_array[i])
	{
		free(splitted_array[i]);
		i++;
	}
	free(splitted_array);
}

void	free_map_elements(t_map_element *head)
{
	t_map_element	*tmp;

	while (head != 0)
	{
		tmp = head;
		head = head->next;
		free(tmp->map_element);
		free(tmp);
	}
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
