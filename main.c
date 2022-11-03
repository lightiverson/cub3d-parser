#include "file_to_str.h"
#include "libft/libft.h"
#include "tokenize.h"
#include "validate_input.h"
#include "validate_map.h"
#include "ll_to_two_d_array.h"

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
	// wat als map_element 0 is? 
	// Kan dit? Vast wel? Dit betekend dat er geen tokens zijn,
	// en dus geen valid characters in de input zitten
	print_map_elements(map_element);

	if (!is_sorted(map_element))
	{
		free(file_str);
		free_map_elements(map_element);
		printf("Error: Map elements are in the wrong order\n");
		exit(EXIT_FAILURE);
	}

	if (has_multiple_start_positions(map_element))
	{
		free(file_str);
		free_map_elements(map_element);
		printf("Error: Map element contains multiple start positions\n");
		exit(EXIT_FAILURE);
	}

	printf("has_two_strs(map_element) = %i\n", has_two_valid_strs(map_element));

	char **a = ll_to_two_d_array(map_element, file_str);
	unsigned int i[2];
	get_start_pos(a, i);

	free(file_str);
	free_map_elements(map_element);

	return (EXIT_SUCCESS);
}
