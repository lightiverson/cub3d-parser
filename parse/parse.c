/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 10:57:51 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/25 12:11:54 by kgajadie      ########   odam.nl         */
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
	cub->floor = parse_floor_ceiling(map_element, SUB_FLOOR);
	free_map_elements(map_element);
	get_start_pos(cub->map, cub->start_pos);
	return (cub);
}
