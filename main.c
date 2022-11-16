#include "file_to_str.h"
#include "libft/libft.h"
#include "tokenize.h"
#include "validate_map.h"
#include "ll_to_a_map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main (int argc, char *argv[argc + 1])
{
	int				map_fd;
	char			*file_str;
	t_map_element	*map_element;

	if (argc != 2) // Check voor exact 1 arg
	{
		printf("Error: Invalid amount of arguments\n");
		exit(EXIT_FAILURE);
	}
	if (!is_dot_cub_file(argv[argc - 1])) // Check of arg eindigdt op .cub
	{
		printf("Error: Invalid file extension\n");
		exit(EXIT_FAILURE);
	}
	
	map_fd = get_map_fd(argv[argc - 1]);
	file_to_str(map_fd, &file_str);
	// printf("file_to_str = |%s|\n", file_str);

	map_element = tokenizer(file_str); // Wat als map_element 0 is?
	// print_map_elements(map_element);

	if (!has_four_cardinals(map_element)) // Check voor exact 4 cardinals
	{
		printf("Error: not 4 cardinals\n");
		exit(EXIT_FAILURE);
	}
	if (!has_two_fcs(map_element)) // Check voor exact 2 floor ceilings
	{
		printf("Error: not 2 floor ceilings\n");
		exit(EXIT_FAILURE);
	}
	if (!has_three_map_elements_min(map_element)) // Check voor min 3 map elements
	{
		printf("Error: less than 3 map elements\n");
		exit(EXIT_FAILURE);
	}

	if (!is_sorted(map_element)) // Check of elementen in de juiste volgorde staan
	{
		printf("Error: not sorted correctly\n");
		exit(EXIT_FAILURE);
	}

	if(!has_four_unique_cardinals(map_element)) // Check voor 4 unieke cardinals
	{
		printf("Error: not 4 unique cardinals or valid cardinals\n");
		exit(EXIT_FAILURE);
	}
	if (!has_two_unique_fcs(map_element)) // Check voor 2 unieke floor ceilings
	{
		printf("Error: not 2 unique floor ceilings or valid floor ceilings\n");
		exit(EXIT_FAILURE);
	}

	if (has_invalid_chars(map_element)) // Check voor valid chars in map
	{
		printf("Error: map contains invalid chars\n");
		exit(EXIT_FAILURE);
	}
	if (!has_single_start_position(map_element)) // Check voor exact 1 start positie
	{
		printf("Error: not 1 start position\n");
		exit(EXIT_FAILURE);
	}

	// Check voor minimum aantal bytes van een valid map (kleinste paths + kleinste map)
	// knal een wrapper functie hierom heen -> is_map_closed

	char			**a_map;
	unsigned int	pos[2];
	
	a_map = ll_to_a_map(map_element);
	// print_splitted_a(a_map);

	get_start_pos(a_map, pos);
	if (!itter_floodfill(a_map, pos, get_map_size(map_element), get_map_col_size(map_element)))
	{
		printf("Map is invalid\n");
		exit(EXIT_FAILURE);
	}

	free(file_str);
	free_map_elements(map_element);
	free_splitted_array(a_map);

	printf("Map is valid!\n");
	return (EXIT_SUCCESS);
}
