/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 12:02:22 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/16 19:04:44 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_exit(char *msg)
{
	printf("%s", msg);
	exit(EXIT_FAILURE);
}

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
		printf("split_a[%i] \t= |%s|\n", i, split_a[i]);
		i++;
	}
}

void	init_data(t_data *data)
{
	data->has_no = false;
	data->has_so = false;
	data->has_we = false;
	data->has_ea = false;
}

void	helper_cardinals(char *first_part, t_data *data)
{
	if (!ft_strncmp(first_part, "NO\0", 3))
		data->has_no = true;
	else if (!ft_strncmp(first_part, "SO\0", 3))
		data->has_so = true;
	else if (!ft_strncmp(first_part, "WE\0", 3))
		data->has_we = true;
	else if (!ft_strncmp(first_part, "EA\0", 3))
		data->has_ea = true;
}
