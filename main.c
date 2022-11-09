#include "file_to_str.h"
#include "libft/libft.h"
#include "tokenize.h"
#include "validate_input.h"
#include "validate_map.h"
#include "ll_to_a_map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void	floodfill(char *map[], int row_pos, int col_pos, bool *is_valid, int rows, int cols)
{
	if (!is_valid)
		return;
	if (col_pos == cols || row_pos == rows || col_pos < 0 || row_pos < 0)
	{
		*is_valid = false;
		return;
	}
	if (map[row_pos][col_pos] == 'X' || map[row_pos][col_pos] == ' ')
	{
		*is_valid = false;
		return;
	}
	if (map[row_pos][col_pos] == '1')
		return;
	if (map[row_pos][col_pos] == 'N' || map[row_pos][col_pos] == 'E' || map[row_pos][col_pos] == 'S' || map[row_pos][col_pos] == 'W')
		map[row_pos][col_pos] = '0';
	if (map[row_pos][col_pos] == '0')
		map[row_pos][col_pos] = '1';
	floodfill(map, row_pos, col_pos + 1, is_valid, rows, cols);
	floodfill(map, row_pos + 1, col_pos, is_valid, rows, cols);
	floodfill(map, row_pos, col_pos - 1, is_valid, rows, cols);
	floodfill(map, row_pos - 1, col_pos, is_valid, rows, cols);
	return;
}

/*
The map must be closed/surrounded by walls, if not the program must return
an error.
*/
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
	printf("file_to_str = |%s|\n", file_str);

	map_element = tokenizer(file_str); // Wat als map_element 0 is?
	print_map_elements(map_element);

	if (!has_four_cardinals(map_element)) // Check voor exact 4 cardinals
	{
		printf("Error: not 4 cardinals");
		exit(EXIT_FAILURE);
	}
	if (!has_floor_ceiling(map_element)) // Check voor exact 2 floor ceilings
	{
		printf("Error: not 2 floor ceilings");
		exit(EXIT_FAILURE);
	}
	if (!has_three_map_elements_min(map_element)) // Check voor min 2 map elements
	{
		printf("Error: less than 3 map elements");
		exit(EXIT_FAILURE);
	}

	if (!is_sorted(map_element)) // Check of elementen in de juiste volgorde staan
	{
		printf("Error: not sorted correctly");
		exit(EXIT_FAILURE);
	}

	if(!has_four_unique_cardinals(map_element)) // Check voor 2 unieke cardinals
	{
		printf("Error: not 4 unique cardinals");
		exit(EXIT_FAILURE);
	}
	if (!has_two_unique_fcs(map_element)) // Check voor 2 unieke floor ceilings
	{
		printf("Error: not 2 unique floor ceilings");
		exit(EXIT_FAILURE);
	}

	// Check voor minimum aantal bytes van een valid map (kleinste paths + kleinste map)
	// Ga door met map validations

	char **a = ll_to_a_map(map_element, file_str);
	print_splitted_a(a);

	bool is_valid = true;
	unsigned int pos[2];
	get_start_pos(a, pos);
	floodfill(a, pos[0], pos[1], &is_valid, get_map_size(map_element), get_map_col_size(map_element));
	if (!is_valid)
		printf("Map is invalid\n");
	else
		printf("Map is valid!\n");

	free(file_str);
	free_map_elements(map_element);

	return (EXIT_SUCCESS);
}
