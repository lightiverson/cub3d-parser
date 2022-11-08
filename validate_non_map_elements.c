/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_non_map_elements.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 17:18:26 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/08 16:04:57 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

static unsigned int	count_ptrs(char **splitted_array)
{
	unsigned int	i;

	i = 0;
	while (splitted_array[i])
		i++;
	return (i);
}

static bool	is_valid_cardinal_fc(char *first_elem)
{
	if (
		!ft_strncmp(first_elem, "NO\0", 3)
		|| !ft_strncmp(first_elem, "SO\0", 3)
		|| !ft_strncmp(first_elem, "WE\0", 3)
		|| !ft_strncmp(first_elem, "EA\0", 3)
		|| !ft_strncmp(first_elem, "F\0", 3)
		|| !ft_strncmp(first_elem, "C\0", 3)
	)
		return (true);
	return (false);
}

bool	has_two_valid_strs(t_map_element *map_element)
{
	char	**splitted_array;

	splitted_array = 0;
	while (map_element)
	{
		if (map_element->type == E_CARDINAL
			|| map_element->type == E_FLOOR_CEILING)
		{
			splitted_array = ft_split(map_element->map_element, ' ');
			if (count_ptrs(splitted_array) != 2)
			{
				free_splitted_array(splitted_array);
				return (false);
			}
			else
				if (!is_valid_cardinal_fc(splitted_array[0]))
					return (false);
		}
		map_element = map_element->next;
	}
	return (true);
}

bool	has_four_cardinals(t_map_element *map_element)
{
	unsigned int	c;

	c = 0;
	while (map_element)
	{
		if (map_element->type == E_CARDINAL)
			c++;
		map_element = map_element->next;
	}
	if (c == 4)
		return (true);
	return (false);
}

bool	has_floor_and_ceiling(t_map_element *map_element)
{
	unsigned int	c;

	c = 0;
	while (map_element)
	{
		if (map_element->type == E_FLOOR_CEILING)
			c++;
		map_element = map_element->next;
	}
	if (c == 2)
		return (true);
	return (false);
}
