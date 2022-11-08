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

	if (argc != 2)
	{
		printf("Error: Invalid amount of arguments\n");
		exit(EXIT_FAILURE);
	}
	if (!is_dot_cub_file(argv[argc - 1]))
	{
		printf("Error: Invalid file extension\n");
		exit(EXIT_FAILURE);
	}
	
	map_fd = get_map_fd(argv[argc - 1]);
	file_to_str(map_fd, &file_str);
	printf("file_to_str = |%s|\n", file_str);

	map_element = tokenizer(file_str);
	print_map_elements(map_element);
	// wat als map_element 0 is? 
	// Kan dit? Vast wel? Dit betekend dat er geen tokens zijn,
	// en dus geen valid characters in de input zitten

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
