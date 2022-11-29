/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 10:57:51 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/29 13:50:55 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char **parse_cordinal(t_map_element *map_element, int sub_type)
{
	char	**splitted_array;
	while (map_element)
	{
		if (map_element->sub_type == sub_type)
			break ;
		map_element = map_element->next;
	}
	if (!map_element)
		print_exit("Error: parser()");
	splitted_array = ft_split(map_element->map_element, ' ');
	if (!splitted_array)
		print_exit("Error: malloc()\n");
	return (splitted_array);
}

t_cub	*parser(t_map_element *map_element)
{
	t_cub			*cub;

	cub = malloc(sizeof(*cub));
	if (!cub)
		print_exit("Error: malloc()");
	cub->rows = get_map_size(map_element);
	cub->cols = get_map_col_size(map_element);
	cub->map = ll_to_a_map(map_element);
	get_start_pos(cub->map, cub->start_pos);
	if (!itter_floodfill(cub->map, cub->start_pos, cub->rows, cub->cols))
		print_exit("Map is not closed\n");
	cub->floor = parse_floor_ceiling(map_element, SUB_FLOOR);
	cub->ceiling = parse_floor_ceiling(map_element, SUB_CEILING);
	cub->no_path = parse_cordinal(map_element, SUB_NO);
	cub->so_path = parse_cordinal(map_element, SUB_SO);
	cub->we_path = parse_cordinal(map_element, SUB_WE);
	cub->ea_path = parse_cordinal(map_element, SUB_EA);
	return (cub);
}
