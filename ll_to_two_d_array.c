/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ll_to_two_d_array.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 11:44:36 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/03 11:45:08 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ll_to_two_d_array.h"

static char	**calloc_two_d_array(t_map_element *map_element)
{
	unsigned int	n;
	char			**two_d_a;

	n = 0;
	while (map_element)
	{
		if (map_element->type == E_MAP)
			n++;
		map_element = map_element->next;
	}
	two_d_a = ft_calloc(n + 1, sizeof(*two_d_a));
	if (!two_d_a)
		return (0);
	return (two_d_a);
}

char	**ll_to_two_d_array(t_map_element *map_element, char *file_str)
{
	unsigned int	i;
	char			**two_d_a;

	i = 0;
	two_d_a = calloc_two_d_array(map_element);
	if (!two_d_a)
	{
		free(file_str);
		free_map_elements(map_element);
		perror("Error: malloc()");
		exit(EXIT_FAILURE);
	}
	while (map_element)
	{
		if (map_element->type == E_MAP)
		{
			two_d_a[i] = map_element->map_element;
			i++;
		}
		map_element = map_element->next;
	}
	print_splitted_a(two_d_a);
	return (two_d_a);
}

static bool	is_start_pos(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (true);
	return (false);
}

int	get_start_pos(char **two_d_a, unsigned int start_pos[2])
{
	unsigned int	sr;
	unsigned int	sc;

	sr = 0;
	sc = 0;
	while (two_d_a[sr])
	{
		while (two_d_a[sr][sc])
		{
			if (is_start_pos(two_d_a[sr][sc]))
			{
				start_pos[0] = sr;
				start_pos[1] = sc;
				printf("start_pos = [%u, %u] = %c\n", start_pos[0],
					start_pos[1], two_d_a[sr][sc]);
				return (1);
			}
			sc++;
		}
		sc = 0;
		sr++;
	}
	return (0);
}
