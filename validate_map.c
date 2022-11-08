/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 16:28:12 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/08 11:10:53 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "validate_map.h"

/*
The map must be composed of only 6 possible characters: 0 for an empty space,
1 for a wall, and N,S,E or W for the player’s start position and spawning
orientation.
*/
bool	has_invalid_chars(t_map_element *map_element)
{
	char	*dup;

	while (map_element)
	{
		if (map_element->type == E_MAP)
		{
			dup = map_element->map_element;
			while (*dup)
			{
				if (*dup != ' ' || *dup != '0' || *dup != '1' || *dup != 'N'
					|| *dup != 'S' || *dup != 'E' || *dup != 'W')
					return (true);
				dup++;
			}
		}
		map_element = map_element->next;
	}
	return (false);
}

bool	has_start_position(t_map_element *map_element)
{
	char	*dup;

	while (map_element)
	{
		if (map_element->type == E_MAP)
		{
			dup = map_element->map_element;
			while (*dup)
			{
				if (*dup == 'N' || *dup == 'S' || *dup == 'E' || *dup == 'W')
					return (true);
				dup++;
			}
		}
		map_element = map_element->next;
	}
	return (false);
}

bool	has_multiple_start_positions(t_map_element *map_element)
{
	char	*dup;
	bool	seen;

	seen = false;
	while (map_element)
	{
		if (map_element->type == E_MAP)
		{
			dup = map_element->map_element;
			while (*dup)
			{
				if (seen && (*dup == 'N' || *dup == 'S' || *dup == 'E'
						|| *dup == 'W'))
					return (true);
				if (!seen && (*dup == 'N' || *dup == 'S' || *dup == 'E'
						|| *dup == 'W'))
					seen = true;
				dup++;
			}
		}
		map_element = map_element->next;
	}
	return (false);
}

int count_columns(t_map_element *map_element)
{
	int	number_of_columns;
	int	x;

	number_of_columns = 0;
	while (map_element)
	{
		if (map_element->type == E_MAP && map_element->map_element)
		{
			x = ft_strlen(map_element->map_element);
			if (x > number_of_columns)
				number_of_columns = x;
		}
		map_element = map_element->next;
	}
	return (number_of_columns);
}
