/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 16:28:12 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/09 17:14:09 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "validate_map.h"

/*
Moet nog getest worden
*/
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

/*
The map must be composed of only 6 possible characters: 0 for an empty space,
1 for a wall, and N,S,E or W for the player’s start position and spawning
orientation.

Moet nog getest worden
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

bool	has_single_start_position(t_map_element *map_element)
{
	char	*dup;
	int		encounters;

	encounters = 0;
	while (map_element)
	{
		if (map_element->type == E_MAP)
		{
			dup = map_element->map_element;
			while (*dup)
			{
				if (*dup == 'N' || *dup == 'S' || *dup == 'E' || *dup == 'W')
					encounters++;
				dup++;
			}
		}
		map_element = map_element->next;
	}
	if (encounters != 1)
		return (false);
	return (true);
}
