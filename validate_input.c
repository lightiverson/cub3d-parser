/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 11:58:06 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/03 11:45:25 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "validate_input.h"

/*
Your program must take as a first argument a scene description file with the .cub
extension.
*/
bool	is_dot_cub_file(char *arg)
{
	size_t	len;
	char	*extension;

	len = ft_strlen(arg);
	if (len < 4)
		return (false);
	extension = arg + len - 4;
	if (ft_strncmp(extension, ".cub\0", 5))
		return (false);
	return (true);
}

/*
Except for the map content which always has to be the last, each type of
element can be set in any order in the file.
*/
bool	is_sorted(t_map_element *map_element)
{
	bool	has_encountered_type_three;

	has_encountered_type_three = false;
	while (map_element)
	{
		if (map_element->type == E_MAP)
			has_encountered_type_three = true;
		if (has_encountered_type_three && map_element->type < E_MAP)
			return (false);
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

bool	has_two_f_c(t_map_element *map_element)
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

bool	has_three_map_elements_min(t_map_element *map_element)
{
	unsigned int	c;

	c = 0;
	while (map_element)
	{
		if (map_element->type == E_MAP)
			c++;
		map_element = map_element->next;
	}
	if (c >= 3)
		return (true);
	return (false);
}
