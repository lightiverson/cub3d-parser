#include "ll_to_two_d_array.h"

static char	**calloc_two_d_array(t_map_element *map_element)
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
	
char	**ll_to_two_d_array(t_map_element *map_element, char *file_str)
{
	unsigned int	i;
	char			**two_d_a;

	i = 0;
	two_d_a = calloc_two_d_array(map_element);
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
