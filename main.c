#include "file_to_str.h"
#include "libft/libft.h"
#include "tokenize.h"
#include "validate_input.h"
#include "validate_map.h"

char	**calloc_two_d_a(t_map_element *map_element)
{
	unsigned int	n;
	char			**two_d_a;

	n = 0;
	while (map_element)
	{
		if (map_element->type == E_MAP)
			n++;
		map_element = map_element->next;
	}
	two_d_a = ft_calloc(n + 1, sizeof(*two_d_a));
	if (!two_d_a)
		return (0);
	return (two_d_a);
}
	
char	**lltotwoda(t_map_element *map_element, char *file_str)
{
	unsigned int	i;
	char			**two_d_a;

	i = 0;
	two_d_a = calloc_two_d_a(map_element);
	if (!two_d_a)
	{
		free(file_str);
		free_map_elements(map_element);
		perror("Error: malloc()");
		exit(EXIT_FAILURE);
	}
	while (map_element)
	{
		if (map_element->type == E_MAP)
		{
			two_d_a[i] = map_element->map_element;
			i++;
		}
		map_element = map_element->next;
	}
	print_splitted_a(two_d_a);
	return (two_d_a);
}

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
	
	free(file_str);
	free_map_elements(map_element);


	return (EXIT_SUCCESS);
}
