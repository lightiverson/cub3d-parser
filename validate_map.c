/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 16:28:12 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/10/26 17:33:03 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "validate_map.h"

static bool has_invalid_chars_inner(char *map_element)
{
	char	*dup;

	dup = map_element;
	while (*dup)
	{
		if (*dup != ' ' || *dup != '0' || *dup != '1' || *dup != 'N'
			|| *dup != 'S'|| *dup != 'E'|| *dup != 'W')
		{
			return (true);
		}
		dup++;
	}
	return (false);
}

bool has_invalid_chars(t_map_element *map_element)
{
	while (map_element)
	{
		if (map_element->type == E_MAP)
			if (has_invalid_chars_inner(map_element->map_element))
				return (true);
		map_element = map_element->next;
	}
	return (false);
}

bool has_start_position(t_map_element *map_element)
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

bool has_multiple_start_positions(t_map_element *map_element)
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
				if (seen && (*dup == 'N' || *dup == 'S' || *dup == 'E' || *dup == 'W'))
					return (true);
				if (!seen && (*dup == 'N' || *dup == 'S' || *dup == 'E' || *dup == 'W'))
					seen = true;
				dup++;
			}
		}
		map_element = map_element->next;
	}
	return (false);
}
