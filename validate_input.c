/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 11:58:06 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/10/26 12:17:29 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "validate_input.h"

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

bool	is_dot_cub_file(char *arg)
{
	size_t	len;
	char	*extension;

	len = strlen(arg);
	if (len < 4)
		return (false);
	extension = arg + len - 4;
	if (strncmp(extension, ".cub\0", 5))
		return (false);
	return (true);
}
