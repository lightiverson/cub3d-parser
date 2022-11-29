/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/29 14:41:44 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/29 15:27:01 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "parse/parse.h"
#include "tokenize/tokenize.h"
#include "validate_tokens/validate_tokens.h"

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
Except for the map content, each type of element can be separated by one or
more empty line(s).
*/
t_map_element	*tokenizer(const char *map_name)
{
	int				map_fd;
	char			*file_str;
	char			**split_a;
	int				i;
	t_map_element	*map_elements;

	map_fd = get_map_fd(map_name);
	file_to_str(map_fd, &file_str);
	split_a = ft_split(file_str, '\n');
	if (!split_a)
		print_exit("Error: ft_split()\n");
	i = 0;
	map_elements = 0;
	while (split_a[i])
	{
		inner_tokenizer(split_a[i], &map_elements);
		i++;
	}
	free_splitted_array(split_a);
	free(file_str);
	return (map_elements);
}

/*
Todo: check voor minimum aantal bytes van een 
valid map (kleinste paths + kleinste map)
*/
void	validate_tokens(t_map_element *map_element)
{
	if (!has_four_cardinals(map_element))
		print_exit("Error: not 4 cardinals\n");
	if (!has_two_fcs(map_element))
		print_exit("Error: not 2 floor ceilings\n");
	if (!has_three_map_elements_min(map_element))
		print_exit("Error: less than 3 map elements\n");
	if (!is_sorted(map_element))
		print_exit("Error: elements not sorted correctly\n");
	if (!has_four_unique_cardinals(map_element))
		print_exit("Error: not 4 unique cardinals or valid cardinals\n");
	if (!has_two_unique_fcs(map_element))
		print_exit("Error: not 2 unique floor ceilings \
			or valid floor ceilings\n");
	if (has_invalid_chars(map_element))
		print_exit("Error: map contains invalid chars\n");
	if (!has_single_start_position(map_element))
		print_exit("Error: not 1 start position\n");
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
		print_exit("Error: map is not closed\n");
	cub->floor = parse_floor_ceiling(map_element, SUB_FLOOR);
	cub->ceiling = parse_floor_ceiling(map_element, SUB_CEILING);
	cub->no_path = parse_cordinal(map_element, SUB_NO);
	cub->so_path = parse_cordinal(map_element, SUB_SO);
	cub->we_path = parse_cordinal(map_element, SUB_WE);
	cub->ea_path = parse_cordinal(map_element, SUB_EA);
	return (cub);
}

int	main(int argc, char *argv[argc + 1])
{
	t_map_element	*map_element;
	t_cub			*cub;

	if (argc != 2)
		print_exit("Error: Invalid amount of arguments\n");
	if (!is_dot_cub_file(argv[argc - 1]))
		print_exit("Error: invalid file extension\n");
	map_element = tokenizer(argv[argc - 1]);
	if (!map_element)
		print_exit("Error: no map_elements\n");
	validate_tokens(map_element);
	cub = parser(map_element);
	free_map_elements(map_element);
	print_cub(cub);
	printf("Map is valid!\n");
	return (EXIT_SUCCESS);
}
