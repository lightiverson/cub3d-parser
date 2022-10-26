/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 12:02:22 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/10/26 12:02:23 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_map_elements(t_map_element *head)
{
	while (head)
	{
		printf("head->map_element = |%s|\n", head->map_element);
		printf("head->type = %i\n", head->type);
		head = head->next;
	}
}

void	print_splitted_a(char **split_a)
{
	unsigned int	i;

	i = 0;
	while (split_a[i])
	{
		printf("split_a[%i] = |%s|\n", i, split_a[i]);
		i++;
	}
}

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
