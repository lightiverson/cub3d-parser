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

int main (int argc, char *argv[argc + 1])
{
	t_map_element	*map_element;
	t_cub			*cub;

	if (argc != 2) // Check voor exact 1 arg
		print_exit("Error: Invalid amount of arguments\n");
	if (!is_dot_cub_file(argv[argc - 1])) // Check of arg eindigdt op .cub
		print_exit("Error: Invalid file extension\n");

	map_element = tokenizer(argv[argc - 1]); // Wat als map_element 0 is?
	// print_map_elements(map_element);

	// if (!has_four_cardinals(map_element)) // Check voor exact 4 cardinals
	// {
	// 	printf("Error: not 4 cardinals\n");
	// 	exit(EXIT_FAILURE);
	// }
	// if (!has_two_fcs(map_element)) // Check voor exact 2 floor ceilings
	// {
	// 	printf("Error: not 2 floor ceilings\n");
	// 	exit(EXIT_FAILURE);
	// }
	// if (!has_three_map_elements_min(map_element)) // Check voor min 3 map elements
	// {
	// 	printf("Error: less than 3 map elements\n");
	// 	exit(EXIT_FAILURE);
	// }

	// if (!is_sorted(map_element)) // Check of elementen in de juiste volgorde staan
	// {
	// 	printf("Error: not sorted correctly\n");
	// 	exit(EXIT_FAILURE);
	// }

	// if(!has_four_unique_cardinals(map_element)) // Check voor 4 unieke cardinals
	// {
	// 	printf("Error: not 4 unique cardinals or valid cardinals\n");
	// 	exit(EXIT_FAILURE);
	// }
	// if (!has_two_unique_fcs(map_element)) // Check voor 2 unieke floor ceilings
	// {
	// 	printf("Error: not 2 unique floor ceilings or valid floor ceilings\n");
	// 	exit(EXIT_FAILURE);
	// }

	// if (has_invalid_chars(map_element)) // Check voor valid chars in map
	// {
	// 	printf("Error: map contains invalid chars\n");
	// 	exit(EXIT_FAILURE);
	// }
	// if (!has_single_start_position(map_element)) // Check voor exact 1 start positie
	// {
	// 	printf("Error: not 1 start position\n");
	// 	exit(EXIT_FAILURE);
	// }
	// // Check voor minimum aantal bytes van een valid map (kleinste paths + kleinste map)

	cub = parser(map_element);
	free_map_elements(map_element);
	print_cub(cub);

	// char *s = strdup("   F   2 2 0 , 1 0  0  ,   0   ");
	// strip_spaces(s);
	// printf("|%s|\n", s);
	// build_rgb(s);
	// free(s);

	printf("Map is valid!\n");
	return (EXIT_SUCCESS);
}
