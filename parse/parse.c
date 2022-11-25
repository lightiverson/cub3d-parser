/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 10:57:51 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/25 14:52:38 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_cub	*parser(t_map_element *map_element)
{
	t_cub			*cub;

	cub = malloc(sizeof(*cub));
	if (!cub)
	{
		perror("Error: malloc()");
		exit(EXIT_FAILURE);
	}
	cub->rows = get_map_size(map_element);
	cub->cols = get_map_col_size(map_element);
	cub->map = ll_to_a_map(map_element);
	// print_splitted_a(cub->map);
	cub->floor = parse_floor_ceiling(map_element, SUB_FLOOR);
	cub->ceiling = parse_floor_ceiling(map_element, SUB_CEILING);
	get_start_pos(cub->map, cub->start_pos);
	if (!itter_floodfill(cub->map, cub->start_pos, cub->rows, cub->cols))
		print_exit("Map is not closed\n");
	return (cub);
}
