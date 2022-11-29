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
Todo: check voor minimum aantal bytes van een valid map (kleinste paths + kleinste map)
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
	if(!has_four_unique_cardinals(map_element))
		print_exit("Error: not 4 unique cardinals or valid cardinals\n");
	if (!has_two_unique_fcs(map_element))
		print_exit("Error: not 2 unique floor ceilings or valid floor ceilings\n");
	if (has_invalid_chars(map_element))
		print_exit("Error: map contains invalid chars\n");
	if (!has_single_start_position(map_element))
		print_exit("Error: not 1 start position\n");
}

int main (int argc, char *argv[argc + 1])
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
