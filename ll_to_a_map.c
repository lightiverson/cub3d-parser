/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ll_to_a_map.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 11:44:36 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/09 10:17:32 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ll_to_a_map.h"

int	get_map_size(t_map_element *map_element)
{
	int	map_size;

	map_size = 0;
	while (map_element)
	{
		if (map_element->type == E_MAP)
			map_size++;
		map_element = map_element->next;
	}
	return (map_size);
}

static char	**calloc_a_map(t_map_element *map_element)
{
	int		map_size;
	char	**a_map;

	map_size = get_map_size(map_element);
	printf("map_size = %i\n", map_size);
	a_map = ft_calloc(map_size + 1, sizeof(*a_map));
	if (!a_map)
		return (0);
	return (a_map);
}

/*
De stap om de map vierkant te maken kan efficienter
*/
char	**ll_to_a_map(t_map_element *map_element, char *file_str)
{
	unsigned int	i;
	char			**a_map;
	int				map_col_size;

	i = 0;
	a_map = calloc_a_map(map_element);
	if (!a_map)
	{
		free(file_str);
		free_map_elements(map_element);
		perror("Error: malloc()");
		exit(EXIT_FAILURE);
	}
	map_col_size = get_map_col_size(map_element);
	while (map_element)
	{
		if (map_element->type == E_MAP && map_element->map_element)
		{
			a_map[i] = ft_calloc(map_col_size + 1, sizeof(*(a_map[i])));
			ft_memset(a_map[i], 'X', map_col_size);
			ft_memcpy(a_map[i], map_element->map_element, ft_strlen(map_element->map_element));
			i++;
		}
		map_element = map_element->next;
	}
	return (a_map);
}
